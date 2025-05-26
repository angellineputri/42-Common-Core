/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:18:55 by aputri-a          #+#    #+#             */
/*   Updated: 2025/01/18 14:22:11 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_pids(t_simulation *sml)
{
	int	i;

	i = 0;
	while (i < sml->number_of_philos)
	{
		kill(sml->philos[i].pid, SIGKILL);
		i++;
	}
	i = 0;
	while (i < sml->number_of_philos)
	{
		waitpid(sml->philos[i].pid, NULL, 0);
		i++;
	}
}

void	free_sml(t_simulation *sml)
{
	if (sml->philos)
	{
		free(sml->philos);
		sml->philos = NULL;
	}
	clean_sem(sml);
}

void	clean_sem(t_simulation *sml)
{
	if (sml->forks.init == 1)
	{
		sem_close(sml->forks.sem);
		sem_unlink("/forks");
	}
	if (sml->data.init == 1)
	{
		sem_close(sml->data.sem);
		sem_unlink("/data");
	}
	if (sml->stop.init == 1)
	{
		sem_close(sml->stop.sem);
		sem_unlink("/stop");
	}
	if (sml->ready.init == 1)
	{
		sem_close(sml->ready.sem);
		sem_unlink("/ready");
	}
	if (sml->eat.init == 1)
	{
		sem_close(sml->eat.sem);
		sem_unlink("/eat");
	}
}
