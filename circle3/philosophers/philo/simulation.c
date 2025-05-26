/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:02:18 by aputri-a          #+#    #+#             */
/*   Updated: 2025/01/18 17:25:30 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_simulation(t_simulation *sml)
{	
	int	i;

	sml->threads = malloc(sizeof(pthread_t) * sml->number_of_philos);
	if (!sml->threads)
		return (ft_err_return("malloc failed"));
	i = 0;
	sml->start_time = timestamp();
	while (i < sml->number_of_philos)
	{
		if (pthread_create(&sml->threads[i], NULL,
				philo_life, (void *)&sml->philos[i]) != 0)
			return (ft_err_return("failed to create thread"));
		i++;
	}
	check_death(sml, 0);
	i = 0;
	while (i < sml->number_of_philos)
	{
		if (pthread_join(sml->threads[i], NULL) != 0)
			return (ft_err_return("failed to join threads"));
		i++;
	}
	return (0);
}

void	check_death(t_simulation *sml, int i)
{
	while (1)
	{
		i = 0;
		while (i < sml->number_of_philos && !sml->a_philo_died)
		{
			pthread_mutex_lock(&sml->philos[i].data);
			if (timestamp() - sml->start_time
				- sml->philos[i].last_ate >= sml->time_to_die)
			{
				pthread_mutex_lock(&sml->stop);
				sml->a_philo_died++;
				print_action(&sml->philos[i], sml, "died");
				pthread_mutex_unlock(&sml->stop);
				pthread_mutex_unlock(&sml->philos[i].data);
				return ;
			}
			pthread_mutex_unlock(&sml->philos[i].data);
			i++;
		}
		pthread_mutex_lock(&sml->stop);
		if (sml->all_ate == sml->number_of_philos)
			break ;
		pthread_mutex_unlock(&sml->stop);
	}
	pthread_mutex_unlock(&sml->stop);
}
