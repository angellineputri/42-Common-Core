/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_char_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:46:10 by aputri-a          #+#    #+#             */
/*   Updated: 2024/10/25 16:09:45 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_char(t_display *dsp)
{
	int	x;
	int	y;

	x = dsp->map.player.x;
	y = dsp->map.player.y;
	if (dsp->cases == IDLE)
	{
		if (dsp->map.data[dsp->map.player.y][dsp->map.player.x] == ' ')
			put_img(dsp, dsp->camo, x, y);
		else
			put_img(dsp, dsp->cat[0][dsp->frame], x, y);
	}
	else if (dsp->cases == RIGHT)
		put_img(dsp, dsp->cat[1][dsp->frame], x - 1, y);
	else if (dsp->cases == LEFT)
		put_img(dsp, dsp->cat[2][dsp->frame], x, y);
	else if (dsp->cases == UP)
		put_img(dsp, dsp->cat[3][dsp->frame], x, y);
	else if (dsp->cases == DOWN)
		put_img(dsp, dsp->cat[4][dsp->frame], x, y - 1);
	else if (dsp->cases == RHW || dsp->cases == LHW)
		render_hit_side(dsp);
	else
		render_hit_vertical(dsp);
	show_counter(dsp);
}

void	render_hit_side(t_display *dsp)
{
	int	x;
	int	y;

	x = dsp->map.player.x;
	y = dsp->map.player.y;
	if (dsp->cases == RHW)
	{
		if (dsp->frame < 2)
			put_img(dsp, dsp->cat[1][dsp->frame], x, y);
		else
			put_img(dsp, dsp->cat[2][dsp->frame + 1], x, y);
		renew(dsp, 1, 0);
	}
	else if (dsp->cases == LHW)
	{
		if (dsp->frame < 2)
			put_img(dsp, dsp->cat[2][dsp->frame], x - 1, y);
		else
			put_img(dsp, dsp->cat[1][dsp->frame + 1], x - 1, y);
		renew(dsp, -1, 0);
	}
}

void	render_hit_vertical(t_display *dsp)
{
	int	x;
	int	y;

	x = dsp->map.player.x;
	y = dsp->map.player.y;
	if (dsp->cases == UHW)
	{
		if (dsp->frame < 2)
			put_img(dsp, dsp->cat[3][dsp->frame], x, y - 1);
		else
			put_img(dsp, dsp->cat[4][dsp->frame + 1], x, y - 1);
		renew(dsp, 0, -1);
	}
	else if (dsp->cases == DHW)
	{
		if (dsp->frame < 2)
			put_img(dsp, dsp->cat[4][dsp->frame], x, y);
		else
			put_img(dsp, dsp->cat[3][dsp->frame + 1], x, y);
		renew(dsp, 0, 1);
	}
}

void	renew(t_display *dsp, int x, int y)
{
	x += dsp->map.player.x;
	y += dsp->map.player.y;
	if (dsp->map.data[y][x] == '1')
		put_img(dsp, dsp->block, x, y);
	else
		put_img(dsp, dsp->gate, x, y);
}
