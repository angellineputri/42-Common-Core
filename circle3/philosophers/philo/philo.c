/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:01:54 by aputri-a          #+#    #+#             */
/*   Updated: 2025/01/18 17:19:46 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_simulation	sml;

	if (argc < 5 || argc > 6)
		return (ft_putstr_fd("./philo number_of_philosophers time_to_die "
				"time_to_eat time_to_sleep "
				"[number_of_times_each_philosopher_must_eat]\n", 2), 1);
	if (init_sml(&sml, argc, argv) == 1)
		return (free_sml(&sml), 1);
	if (start_simulation(&sml) == 1)
		return (free_sml(&sml), 1);
	free_sml(&sml);
	return (0);
}
