/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:46:05 by aputri-a          #+#    #+#             */
/*   Updated: 2024/10/22 01:48:20 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(t_display *dsp)
{
	int		x;
	int		y;
	void	*img;

	file_to_img(dsp);
	y = -1;
	while (y++ < dsp->map.rows - 1)
	{
		x = -1;
		while (x++ < dsp->map.cols - 1)
		{
			if (dsp->map.data[y][x] == '1')
				img = dsp->block.img;
			else if (dsp->map.data[y][x] == '0')
				img = dsp->bg.img;
			else if (dsp->map.data[y][x] == 'E')
				img = dsp->gate.img;
			else if (dsp->map.data[y][x] == 'P')
				img = dsp->cat.img;
			else
				img = dsp->key.img;
			mlx_put_image_to_window(dsp->mlx, dsp->window,
				img, SIZE * x, SIZE * y);
		}
	}
}

void	file_to_img(t_display *dsp)
{
	dsp->window = mlx_new_window(dsp->mlx, SIZE * dsp->map.cols,
			SIZE * dsp->map.rows, "so_long");
	if (!dsp->window)
		exit_program(dsp, 1);
	dsp->block.img = mlx_xpm_file_to_image(dsp->mlx, "./textures/xpm/block.xpm",
			&dsp->block.img_width, &dsp->block.img_height);
	dsp->gate.img = mlx_xpm_file_to_image(dsp->mlx, "./textures/xpm/gate.xpm",
			&dsp->gate.img_width, &dsp->gate.img_height);
	dsp->cat.img = mlx_xpm_file_to_image(dsp->mlx, "./textures/xpm/cat.xpm",
			&dsp->cat.img_width, &dsp->cat.img_height);
	dsp->key.img = mlx_xpm_file_to_image(dsp->mlx, "./textures/xpm/key.xpm",
			&dsp->key.img_width, &dsp->key.img_height);
	dsp->bg.img = mlx_xpm_file_to_image(dsp->mlx, "./textures/xpm/bg.xpm",
			&dsp->bg.img_width, &dsp->bg.img_height);
	if (!dsp->block.img || !dsp->gate.img || !dsp->cat.img
		|| !dsp->key.img || !dsp->bg.img)
		exit_program(dsp, 1);
}
