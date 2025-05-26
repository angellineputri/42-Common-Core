/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:19:14 by aputri-a          #+#    #+#             */
/*   Updated: 2025/02/12 15:19:13 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	philo_life(t_philo *philo)
{
	t_simulation	*sml;

	sml = philo->sml;
	sem_wait(sml->ready.sem);
	if (pthread_create(&philo->check_death, NULL, check_death, (void *)philo))
		return (ft_err_return("failed to create thread"));
	if (sml->number_of_philos == 1)
	{
		return (one_philo(philo, sml));
	}
	if (philo->number % 2 == 1)
	{
		print_action(philo, sml, "is thinking");
		msleep(sml->time_to_eat);
		if (philo->number == sml->number_of_philos)
			msleep(sml->time_to_eat);
	}
	philo_routine(philo, sml);
	return (0);
}

int	one_philo(t_philo *philo, t_simulation *sml)
{
	print_action(philo, sml, "has taken a fork");
	return (0);
}

void	philo_routine(t_philo *philo, t_simulation *sml)
{
	while (1)
	{
		philo_eats(philo, sml);
		if (philo->eat_amt == sml->max_eat_amt)
		{
			sem_post(sml->eat.sem);
			return ;
		}
		print_action(philo, sml, "is sleeping");
		msleep(sml->time_to_sleep);
		print_action(philo, sml, "is thinking");
		usleep(500);
	}
}

void	philo_eats(t_philo *philo, t_simulation *sml)
{
	sem_wait(sml->forks.sem);
	print_action(philo, sml, "has taken a fork");
	sem_wait(sml->forks.sem);
	print_action(philo, sml, "has taken a fork");
	print_action(philo, sml, "is eating");
	sem_wait(sml->data.sem);
	philo->eat_amt++;
	sem_post(sml->data.sem);
	msleep(sml->time_to_eat);
	sem_wait(sml->data.sem);
	philo->last_ate = timestamp() - sml->start_time;
	sem_post(sml->data.sem);
	sem_post(sml->forks.sem);
	sem_post(sml->forks.sem);
}

void	*check_death(void *arg)
{
	t_philo			*philo;
	t_simulation	*sml;

	philo = (t_philo *) arg;
	sml = philo->sml;
	while (1)
	{
		sem_wait(sml->data.sem);
		if (timestamp() - sml->start_time - philo->last_ate >= sml->time_to_die)
		{
			print_action(philo, sml, "died");
			sem_post(sml->stop.sem);
			return (NULL);
		}
		sem_post(sml->data.sem);
		sem_wait(sml->data.sem);
		if (philo->eat_amt == sml->max_eat_amt)
		{
			sem_post(sml->data.sem);
			return (NULL);
		}
		sem_post(sml->data.sem);
		usleep(100);
	}
}
