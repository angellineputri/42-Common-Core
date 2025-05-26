/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:47:18 by aputri-a          #+#    #+#             */
/*   Updated: 2024/10/25 16:12:12 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	update(t_display *dsp)
{
	int	frame;

	frame = max_frame(dsp);
	dsp->frame = dsp->frame % frame;
	render_map(dsp);
	render_char(dsp);
	render_patrol(dsp);
	usleep(41235);
	dsp->frame++;
	if (dsp->frame % frame == 0)
		dsp->cases = IDLE;
	return (0);
}

int	max_frame(t_display *dsp)
{
	if (dsp->cases == IDLE)
		return (8);
	else if (dsp->cases == RIGHT || dsp->cases == LEFT)
		return (5);
	else if (dsp->cases == UP || dsp->cases == DOWN
		|| dsp->cases == RHW || dsp->cases == LHW)
		return (4);
	else if (dsp->cases == UHW || dsp->cases == DHW)
		return (3);
	return (0);
}
