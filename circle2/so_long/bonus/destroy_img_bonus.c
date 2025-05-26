/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 02:34:57 by aputri-a          #+#    #+#             */
/*   Updated: 2024/10/25 15:47:40 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_img(t_display *dsp)
{
	if (dsp->block)
		mlx_destroy_image(dsp->mlx, dsp->block);
	if (dsp->gate)
		mlx_destroy_image(dsp->mlx, dsp->gate);
	if (dsp->key)
		mlx_destroy_image(dsp->mlx, dsp->key);
	if (dsp->bg)
		mlx_destroy_image(dsp->mlx, dsp->bg);
	if (dsp->lightkey)
		mlx_destroy_image(dsp->mlx, dsp->lightkey);
	if (dsp->camo)
		mlx_destroy_image(dsp->mlx, dsp->camo);
	if (dsp->camolight)
		mlx_destroy_image(dsp->mlx, dsp->camolight);
	if (dsp->light)
		mlx_destroy_image(dsp->mlx, dsp->light);
	destroy_char_idle(dsp);
	destroy_char_side(dsp);
	destroy_char_vertical(dsp);
}

void	destroy_char_idle(t_display *dsp)
{
	if (dsp->cat[0][0])
		mlx_destroy_image(dsp->mlx, dsp->cat[0][0]);
	if (dsp->cat[0][1])
		mlx_destroy_image(dsp->mlx, dsp->cat[0][1]);
	if (dsp->cat[0][2])
		mlx_destroy_image(dsp->mlx, dsp->cat[0][2]);
	if (dsp->cat[0][3])
		mlx_destroy_image(dsp->mlx, dsp->cat[0][3]);
	if (dsp->cat[0][4])
		mlx_destroy_image(dsp->mlx, dsp->cat[0][4]);
	if (dsp->cat[0][5])
		mlx_destroy_image(dsp->mlx, dsp->cat[0][5]);
	if (dsp->cat[0][6])
		mlx_destroy_image(dsp->mlx, dsp->cat[0][6]);
	if (dsp->cat[0][7])
		mlx_destroy_image(dsp->mlx, dsp->cat[0][7]);
}

void	destroy_char_side(t_display *dsp)
{
	if (dsp->cat[1][0])
		mlx_destroy_image(dsp->mlx, dsp->cat[1][0]);
	if (dsp->cat[1][1])
		mlx_destroy_image(dsp->mlx, dsp->cat[1][1]);
	if (dsp->cat[1][2])
		mlx_destroy_image(dsp->mlx, dsp->cat[1][2]);
	if (dsp->cat[1][3])
		mlx_destroy_image(dsp->mlx, dsp->cat[1][3]);
	if (dsp->cat[1][4])
		mlx_destroy_image(dsp->mlx, dsp->cat[1][4]);
	if (dsp->cat[2][0])
		mlx_destroy_image(dsp->mlx, dsp->cat[2][0]);
	if (dsp->cat[2][1])
		mlx_destroy_image(dsp->mlx, dsp->cat[2][1]);
	if (dsp->cat[2][2])
		mlx_destroy_image(dsp->mlx, dsp->cat[2][2]);
	if (dsp->cat[2][3])
		mlx_destroy_image(dsp->mlx, dsp->cat[2][3]);
	if (dsp->cat[2][4])
		mlx_destroy_image(dsp->mlx, dsp->cat[2][4]);
}

void	destroy_char_vertical(t_display *dsp)
{
	if (dsp->cat[3][0])
		mlx_destroy_image(dsp->mlx, dsp->cat[3][0]);
	if (dsp->cat[3][1])
		mlx_destroy_image(dsp->mlx, dsp->cat[3][1]);
	if (dsp->cat[3][2])
		mlx_destroy_image(dsp->mlx, dsp->cat[3][2]);
	if (dsp->cat[3][3])
		mlx_destroy_image(dsp->mlx, dsp->cat[3][3]);
	if (dsp->cat[4][0])
		mlx_destroy_image(dsp->mlx, dsp->cat[4][0]);
	if (dsp->cat[4][1])
		mlx_destroy_image(dsp->mlx, dsp->cat[4][1]);
	if (dsp->cat[4][2])
		mlx_destroy_image(dsp->mlx, dsp->cat[4][2]);
	if (dsp->cat[4][3])
		mlx_destroy_image(dsp->mlx, dsp->cat[4][3]);
}
