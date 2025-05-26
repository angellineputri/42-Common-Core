/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:01:31 by aputri-a          #+#    #+#             */
/*   Updated: 2025/01/18 17:57:19 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_sml(t_simulation *sml)
{
	int	i;

	if (sml->forks)
		free(sml->forks);
	if (sml->forks_mutex)
	{
		i = 0;
		while (i < sml->number_of_philos)
			pthread_mutex_destroy(&sml->forks_mutex[i++]);
		free(sml->forks_mutex);
		sml->forks_mutex = NULL;
	}
	if (sml->philos)
	{
		free(sml->philos);
		sml->philos = NULL;
	}
	if (sml->threads)
	{
		free(sml->threads);
		sml->threads = NULL;
	}
	if (sml->stop_mutex_init == 1)
		pthread_mutex_destroy(&sml->stop);
}
