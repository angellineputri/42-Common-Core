/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:02:04 by aputri-a          #+#    #+#             */
/*   Updated: 2025/01/18 17:59:01 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_life(void *arg)
{
	t_philo			*philo;
	t_simulation	*sml;

	philo = (t_philo *)arg;
	sml = philo->sml;
	if (sml->number_of_philos == 1)
	{
		one_philo(philo, sml);
		return (0);
	}
	if (philo->number % 2 == 1)
	{
		print_action(philo, sml, "is thinking");
		msleep(sml, sml->time_to_eat);
		if (philo->number == sml->number_of_philos)
			msleep(sml, sml->time_to_eat);
	}
	philo_routine(philo, sml);
	return (0);
}

void	one_philo(t_philo *philo, t_simulation *sml)
{
	print_action(philo, sml, "has taken a fork");
	while (1)
	{
		pthread_mutex_lock(&sml->stop);
		if (sml->a_philo_died)
		{
			pthread_mutex_unlock(&sml->stop);
			break ;
		}
		pthread_mutex_unlock(&sml->stop);
	}
}

void	philo_routine(t_philo *philo, t_simulation *sml)
{
	while (1)
	{
		pthread_mutex_lock(&sml->stop);
		if (sml->a_philo_died || sml->all_ate == sml->number_of_philos)
		{
			pthread_mutex_unlock(&sml->stop);
			break ;
		}
		pthread_mutex_unlock(&sml->stop);
		philo_eats(philo, sml);
		pthread_mutex_lock(&sml->stop);
		if (sml->a_philo_died || sml->all_ate == sml->number_of_philos)
		{
			pthread_mutex_unlock(&sml->stop);
			break ;
		}
		pthread_mutex_unlock(&sml->stop);
		print_action(philo, sml, "is sleeping");
		msleep(sml, sml->time_to_sleep);
		print_action(philo, sml, "is thinking");
		usleep(500);
	}
}

void	philo_eats(t_philo *philo, t_simulation *sml)
{
	if (philo->eat_amt == sml->max_eat_amt)
		return ;
	can_philo_eat(philo, sml);
	take_fork(sml, philo->left_fork);
	print_action(philo, sml, "has taken a fork");
	take_fork(sml, philo->right_fork);
	print_action(philo, sml, "has taken a fork");
	pthread_mutex_lock(&philo->data);
	philo->eat_amt++;
	pthread_mutex_unlock(&philo->data);
	print_action(philo, sml, "is eating");
	if (philo->eat_amt == sml->max_eat_amt)
	{
		pthread_mutex_lock(&sml->stop);
		sml->all_ate++;
		pthread_mutex_unlock(&sml->stop);
	}
	msleep(sml, sml->time_to_eat);
	pthread_mutex_lock(&philo->data);
	philo->last_ate = timestamp() - sml->start_time;
	pthread_mutex_unlock(&philo->data);
	release_fork(sml, philo->left_fork);
	release_fork(sml, philo->right_fork);
}

void	can_philo_eat(t_philo *philo, t_simulation *sml)
{
	while (1)
	{
		if (philo->number == sml->number_of_philos)
			break ;
		pthread_mutex_lock(&philo->data);
		pthread_mutex_lock(&sml->philos[sml->number_of_philos - 1].data);
		if (philo->eat_amt > sml->philos[sml->number_of_philos - 1].eat_amt)
		{
			pthread_mutex_unlock(&sml->philos[sml->number_of_philos - 1].data);
			pthread_mutex_unlock(&philo->data);
			usleep(500);
		}
		else
		{
			pthread_mutex_unlock(&sml->philos[sml->number_of_philos - 1].data);
			pthread_mutex_unlock(&philo->data);
			break ;
		}
	}
}
