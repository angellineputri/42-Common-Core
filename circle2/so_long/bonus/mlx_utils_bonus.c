/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:46:01 by aputri-a          #+#    #+#             */
/*   Updated: 2024/10/25 16:08:56 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*load_img(t_display *dsp, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(dsp->mlx, path,
			&dsp->width, &dsp->height);
	if (!img)
	{
		ft_putstr_fd("fail to load \'", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\'\n", 2);
		exit_program(dsp, 1);
	}
	return (img);
}

void	put_img(t_display *dsp, void *img, int x, int y)
{
	mlx_put_image_to_window(dsp->mlx, dsp->window, img, SIZE * x, SIZE * y);
}
