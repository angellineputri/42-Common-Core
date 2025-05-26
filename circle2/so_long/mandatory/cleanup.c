/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 04:34:07 by aputri-a          #+#    #+#             */
/*   Updated: 2024/10/21 22:10:28 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_program(t_display *dsp, int ex)
{
	if (dsp->window)
		mlx_destroy_window(dsp->mlx, dsp->window);
	if (dsp->block.img)
		mlx_destroy_image(dsp->mlx, dsp->block.img);
	if (dsp->gate.img)
		mlx_destroy_image(dsp->mlx, dsp->gate.img);
	if (dsp->cat.img)
		mlx_destroy_image(dsp->mlx, dsp->cat.img);
	if (dsp->key.img)
		mlx_destroy_image(dsp->mlx, dsp->key.img);
	if (dsp->bg.img)
		mlx_destroy_image(dsp->mlx, dsp->bg.img);
	if (dsp->mlx)
	{
		mlx_destroy_display(dsp->mlx);
		free(dsp->mlx);
	}
	ft_free_2d(&dsp->map.data);
	free_collectable(dsp);
	exit_status(dsp, &ex);
	exit(ex);
}

int	exit_close_win(t_display *dsp)
{
	exit_program(dsp, 0);
	return (0);
}

void	exit_status(t_display *dsp, int *ex)
{
	if ((*ex) == -1)
	{
		ft_putstr_fd("you won with ", 1);
		ft_putnbr_fd(dsp->move, 1);
		ft_putstr_fd(" moves!\n", 1);
		(*ex)++;
	}
	else if ((*ex) == 0)
	{
		ft_putstr_fd("is it too hard? :(\n", 1);
	}
}
