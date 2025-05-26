/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:19:19 by aputri-a          #+#    #+#             */
/*   Updated: 2025/02/12 15:20:15 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	start_simulation(t_simulation *sml)
{	
	int	i;
	int	save_exit;

	i = 0;
	sml->start_time = timestamp();
	while (i < sml->number_of_philos)
	{
		sml->philos[i].pid = fork();
		if (sml->philos[i].pid < 0)
			return (ft_err_return("failed to fork"));
		if (sml->philos[i].pid == 0)
		{
			save_exit = philo_life(&sml->philos[i]);
			if (pthread_join(sml->philos[i].check_death, NULL) != 0)
				return (ft_err_return("failed to join threads"));
			free_sml(sml);
			exit(save_exit);
		}
		i++;
	}
	if (pthread_create(&sml->track_eat, NULL, track_eat, (void *)sml) != 0)
		return (ft_err_return("failed to create thread"));
	end_simulation(sml);
	return (0);
}

void	end_simulation(t_simulation *sml)
{
	int	i;

	i = 0;
	while (i < sml->number_of_philos)
	{
		sem_post(sml->ready.sem);
		i++;
	}
	sem_wait(sml->stop.sem);
	i = 0;
	while (i < sml->number_of_philos)
	{
		sem_post(sml->eat.sem);
		i++;
	}
	pthread_join(sml->track_eat, NULL);
	free_pids(sml);
	free_sml(sml);
}

void	*track_eat(void *arg)
{
	int				i;
	t_simulation	*sml;

	i = 0;
	sml = (t_simulation *) arg;
	while (i < sml->number_of_philos)
	{
		sem_wait(sml->eat.sem);
		i++;
	}
	sem_post(sml->stop.sem);
	return (NULL);
}
