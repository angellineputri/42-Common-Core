/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:19:03 by aputri-a          #+#    #+#             */
/*   Updated: 2025/02/12 15:20:47 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_simulation	sml;

	if (argc < 5 || argc > 6)
		return (ft_putstr_fd("./philo_bonus number_of_philosophers "
				"time_to_die time_to_eat time_to_sleep "
				"[number_of_times_each_philosopher_must_eat]\n", 2), 1);
	if (init_sml(&sml, argc, argv) == 1)
		return (free_sml(&sml), 1);
	if (start_simulation(&sml) == 1)
		return (free_sml(&sml), 1);
	return (0);
}
