/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 04:34:07 by aputri-a          #+#    #+#             */
/*   Updated: 2024/10/25 15:47:36 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	exit_program(t_display *dsp, int ex)
{
	destroy_img(dsp);
	if (dsp->window)
		mlx_destroy_window(dsp->mlx, dsp->window);
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
		ft_putstr_fd("You lost! Is it too hard? :(\n", 1);
	}
}
