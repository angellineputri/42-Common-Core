/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 01:09:26 by aputri-a          #+#    #+#             */
/*   Updated: 2024/10/25 16:09:58 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render(t_display *dsp)
{
	dsp->initial.x = dsp->map.player.x;
	dsp->initial.y = dsp->map.player.y;
	setup(dsp);
	render_map(dsp);
	show_counter(dsp);
	put_img(dsp, dsp->cat[0][0], dsp->map.player.x, dsp->map.player.y);
}

void	render_map(t_display *dsp)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (y < dsp->map.rows)
	{
		x = -1;
		while (x++ < dsp->map.cols - 1)
		{
			if (dsp->map.data[y][x] == '1')
				img = dsp->block;
			else if (dsp->map.data[y][x] == 'E')
				img = dsp->gate;
			else if (dsp->map.data[y][x] == 'C')
				img = decide_key(dsp, x, y);
			else
				img = dsp->bg;
			mlx_put_image_to_window(dsp->mlx, dsp->window,
				img, SIZE * x, SIZE * y);
		}
		y++;
	}
}

void	*decide_key(t_display *dsp, int x, int y)
{
	void	*img;
	t_pos	*current;

	current = dsp->map.collectable;
	while (current)
	{
		if (current->x == x && current->y == y)
			break ;
		current = current->next;
	}
	current->found += rand() % 3;
	if (current->found % 40 < 20)
		img = dsp->lightkey;
	else
		img = dsp->key;
	return (img);
}

void	show_counter(t_display *dsp)
{
	char	*str;
	char	*num;
	int		i;

	num = ft_itoa(dsp->move);
	if (!num)
	{
		perror("itoa");
		exit_program(dsp, 1);
	}
	str = ft_strjoin("moves: ", num);
	free(num);
	if (!str)
	{
		perror("ft_strjoin");
		exit_program(dsp, 1);
	}
	i = 0;
	while (i < dsp->map.cols)
	{
		put_img(dsp, dsp->block, i, 0);
		i++;
	}
	mlx_string_put(dsp->mlx, dsp->window, 16, 16, 0xFFFFFF, str);
	free(str);
}
