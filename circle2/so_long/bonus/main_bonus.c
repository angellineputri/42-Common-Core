/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 01:02:34 by aputri-a          #+#    #+#             */
/*   Updated: 2024/10/25 16:08:37 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	mlx_hook(dsp.window, 17, 1L << 2, &exit_close_win, &dsp);
	mlx_hook(dsp.window, 2, 1L << 0, &input_handler, &dsp);
	mlx_hook(dsp.window, 3, 1L << 1, &key_release, &dsp);
	mlx_loop_hook(dsp.mlx, &update, &dsp);
	mlx_loop(dsp.mlx);
}
