/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_patrol_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:46:34 by aputri-a          #+#    #+#             */
/*   Updated: 2024/10/25 16:11:27 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_patrol(t_display *dsp)
{
	int	y;
	int	x;

	y = 0;
	while (y < dsp->map.rows)
	{
		x = dsp->patrol % dsp->map.cols;
		if (y % 2 == 0)
			x = dsp->map.cols - x - 1;
		if (dsp->map.data[y][x] == '0' || dsp->map.data[y][x] == 'L')
			put_light(dsp, x, y, 0);
		else if (dsp->map.data[y][x] == ' ')
			put_light(dsp, x, y, 1);
		else if (dsp->patrol < dsp->map.cols
			&& x == dsp->initial.x && y == dsp->initial.y)
			y += 0;
		else if (dsp->map.data[y][x] == 'P')
			exit_program(dsp, 0);
		y++;
	}
	dsp->patrol_frame++;
	if (dsp->patrol_frame % 20 == 0)
		dsp->patrol++;
}

void	put_light(t_display *dsp, int x, int y, int camo)
{
	int	i;

	i = 0;
	while (i < dsp->map.cols)
	{
		if (dsp->map.data[y][i] == 'L')
			dsp->map.data[y][i] = '0';
	}
	if (camo == 0)
	{
		dsp->map.data[y][x] = 'L';
		put_img(dsp, dsp->light, x, y);
	}
	else
		put_img(dsp, dsp->camolight, x, y);
}
