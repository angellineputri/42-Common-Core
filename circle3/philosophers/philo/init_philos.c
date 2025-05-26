/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:01:39 by aputri-a          #+#    #+#             */
/*   Updated: 2025/01/18 17:57:02 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_all_philos(t_simulation *sml)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = malloc(sizeof(t_philo) * (sml->number_of_philos));
	if (!philos)
		return (ft_err_return("malloc failed"));
	while (i < sml->number_of_philos)
	{
		init_philo(sml, &philos[i], i);
		i++;
	}
	i = 0;
	sml->philos = philos;
	return (0);
}

void	init_philo(t_simulation *sml, t_philo *new_philo, int i)
{
	(*new_philo) = (t_philo){0};
	new_philo->sml = sml;
	new_philo->number = i + 1;
	new_philo->left_fork = i;
	if (i != sml->number_of_philos - 1)
		new_philo->right_fork = i + 1;
	else
		new_philo->right_fork = 0;
}
