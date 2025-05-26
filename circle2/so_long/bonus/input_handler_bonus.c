/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:16:25 by aputri-a          #+#    #+#             */
/*   Updated: 2024/10/25 16:07:11 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	input_handler(int keysym, t_display *dsp)
{
	if (keysym == XK_Escape)
		exit_program(dsp, 0);
	if (dsp->cases != IDLE)
		return (0);
	if (keysym == XK_space)
		dsp->map.data[dsp->map.player.y][dsp->map.player.x] = ' ';
	else if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		move_decider(0, -1, dsp, UP);
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		move_decider(-1, 0, dsp, LEFT);
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		move_decider(0, 1, dsp, DOWN);
	else if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		move_decider(1, 0, dsp, RIGHT);
	return (0);
}

void	move_decider(int x, int y, t_display *dsp, t_cases direction)
{
	dsp->cases = direction;
	dsp->frame = 0;
	if (dsp->map.data[dsp->map.player.y + y][dsp->map.player.x + x] == '1'
		|| (dsp->map.data[dsp->map.player.y + y][dsp->map.player.x + x] == 'E'
		&& dsp->map.c_count != 0))
	{
		player_hit(dsp);
		return ;
	}
	else if (dsp->map.data[dsp->map.player.y + y][dsp->map.player.x + x] == 'C')
		collect(dsp, x, y);
	dsp->move++;
	if (dsp->map.data[dsp->map.player.y + y][dsp->map.player.x + x] == 'E')
		exit_program(dsp, -1);
	dsp->map.data[dsp->map.player.y][dsp->map.player.x] = '0';
	dsp->map.data[dsp->map.player.y + y][dsp->map.player.x + x] = 'P';
	dsp->map.player.x += x;
	dsp->map.player.y += y;
}

void	player_hit(t_display *dsp)
{
	if (dsp->cases == RIGHT)
		dsp->cases = RHW;
	else if (dsp->cases == LEFT)
		dsp->cases = LHW;
	else if (dsp->cases == UP)
		dsp->cases = UHW;
	else if (dsp->cases == DOWN)
		dsp->cases = DHW;
}

void	collect(t_display *dsp, int x, int y)
{
	t_pos	*current;

	x += dsp->map.player.x;
	y += dsp->map.player.y;
	current = dsp->map.collectable;
	while (current)
	{
		if (current->x == x && current->y == y)
			break ;
		current = current->next;
	}
	if (current->found % 40 < 20)
		exit_program(dsp, 0);
	else
	{
		dsp->map.c_count--;
	}
}

int	key_release(int keysym, t_display *dsp)
{
	if (keysym == XK_space)
		dsp->map.data[dsp->map.player.y][dsp->map.player.x] = 'P';
	return (0);
}
