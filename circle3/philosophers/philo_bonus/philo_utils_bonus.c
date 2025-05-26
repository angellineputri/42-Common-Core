/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:19:16 by aputri-a          #+#    #+#             */
/*   Updated: 2025/02/12 15:17:51 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	msleep(int time)
{
	long	start;

	start = timestamp();
	while (timestamp() - start < time)
	{
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
	sem_wait(sml->data.sem);
	printf("%ld %d %s\n", time - sml->start_time, philo->number, action);
	sem_post(sml->data.sem);
	return ;
}

long	timestamp(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (ft_putstr_fd("failed to gettimeofday\n", 2), -1);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
