/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:02:51 by aputri-a          #+#    #+#             */
/*   Updated: 2024/10/22 01:08:41 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_display	dsp;

	if (argc != 2)
		return (ft_putstr_fd("./so_long map.ber\n", 1), 1);
	dsp = (t_display){0};
	assign_map(&dsp, argv[1]);
	check_map(&dsp);
	check_valid_path(&dsp);
	dsp.mlx = mlx_init();
	if (!dsp.mlx)
		exit_program(&dsp, 1);
	render(&dsp);
	mlx_hook(dsp.window, 2, 1L << 0, &handle_keyboard_input, &dsp);
	mlx_hook(dsp.window, 17, 1L << 2, &exit_close_win, &dsp);
	mlx_loop(dsp.mlx);
}
