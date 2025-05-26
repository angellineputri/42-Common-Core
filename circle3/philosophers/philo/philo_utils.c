/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:02:12 by aputri-a          #+#    #+#             */
/*   Updated: 2025/01/18 17:58:41 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msleep(t_simulation *sml, int time)
{
	long	start;

	start = timestamp();
	while (timestamp() - start < time)
	{
		pthread_mutex_lock(&sml->stop);
		if (sml->a_philo_died || sml->all_ate == sml->number_of_philos)
		{
			pthread_mutex_unlock(&sml->stop);
			return ;
		}
		pthread_mutex_unlock(&sml->stop);
		usleep(200);
	}
}

void	print_action(t_philo *philo, t_simulation *sml, char *action)
{
	long	time;

	time = timestamp();
	if (ft_strcmp(action, "died") == 0)
	{
		printf("%ld %d %s\n", time - sml->start_time, philo->number, action);
		return ;
	}
	pthread_mutex_lock(&sml->stop);
	if (sml->a_philo_died != 0 || (sml->all_ate == sml->number_of_philos
			&& ft_strcmp(action, "is eating") != 0))
	{
		pthread_mutex_unlock(&sml->stop);
		return ;
	}
	printf("%ld %d %s\n", time - sml->start_time, philo->number, action);
	pthread_mutex_unlock(&sml->stop);
	return ;
}

long	timestamp(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (ft_putstr_fd("failed to gettimeofday\n", 2), -1);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	take_fork(t_simulation *sml, int fork)
{
	while (1)
	{
		pthread_mutex_lock(&sml->forks_mutex[fork]);
		if (sml->forks[fork])
		{
			sml->forks[fork] = 0;
			pthread_mutex_unlock(&sml->forks_mutex[fork]);
			break ;
		}
		pthread_mutex_unlock(&sml->forks_mutex[fork]);
		usleep(100);
	}
}

void	release_fork(t_simulation *sml, int fork)
{
	pthread_mutex_lock(&sml->forks_mutex[fork]);
	sml->forks[fork] = 1;
	pthread_mutex_unlock(&sml->forks_mutex[fork]);
}
