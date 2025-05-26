/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:16:25 by aputri-a          #+#    #+#             */
/*   Updated: 2024/10/25 16:01:25 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keyboard_input(int keysym, t_display *dsp)
{
	if (keysym == XK_Escape)
		exit_program(dsp, 0);
	else if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		move_player(0, -1, dsp);
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		move_player(-1, 0, dsp);
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		move_player(0, 1, dsp);
	else if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		move_player(1, 0, dsp);
	return (0);
}

void	move_player(int x, int y, t_display *dsp)
{
	if (dsp->map.data[dsp->map.player.y + y][dsp->map.player.x + x] == '1'
		|| (dsp->map.data[dsp->map.player.y + y][dsp->map.player.x + x] == 'E'
		&& dsp->map.c_count != 0))
		return ;
	else if (dsp->map.data[dsp->map.player.y + y][dsp->map.player.x + x] == 'C')
		dsp->map.c_count--;
	renew('0', dsp->bg.img, dsp);
	dsp->map.player.x += x;
	dsp->map.player.y += y;
	if (dsp->map.data[dsp->map.player.y][dsp->map.player.x] != 'E')
		renew('P', dsp->cat.img, dsp);
	dsp->move++;
	show_counter(dsp);
	if (dsp->map.data[dsp->map.player.y][dsp->map.player.x] == 'E')
		exit_program(dsp, -1);
}

void	renew(char new_data, void *new_img, t_display *dsp)
{
	dsp->map.data[dsp->map.player.y][dsp->map.player.x] = new_data;
	mlx_put_image_to_window(dsp->mlx, dsp->window, new_img,
		SIZE * dsp->map.player.x, SIZE * dsp->map.player.y);
}

void	show_counter(t_display *dsp)
{
	ft_putstr_fd("moves: ", 1);
	ft_putnbr_fd(dsp->move, 1);
	ft_putchar_fd('\n', 1);
}
