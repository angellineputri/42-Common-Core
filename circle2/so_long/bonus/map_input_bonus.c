/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_input_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:21:44 by aputri-a          #+#    #+#             */
/*   Updated: 2024/10/25 15:47:47 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_map(char *msg, t_display *dsp)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	if (dsp->map.data)
		ft_free_2d(&dsp->map.data);
	if (dsp->map.data_copy)
		ft_free_2d(&dsp->map.data_copy);
	if (dsp->map.c_count != 0)
		free_collectable(dsp);
	exit(1);
}

void	assign_map(t_display *dsp, char *file)
{
	int		fd;

	dsp->map.rows = 0;
	check_map_name(file);
	count_rows(dsp, file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error_handling(file);
	dsp->map.data = fill_map(dsp, fd);
	close(fd);
	count_cols(dsp);
}

void	check_map(t_display *dsp)
{
	int	rows;
	int	cols;

	rows = -1;
	while (rows++ < dsp->map.rows - 1)
	{
		cols = -1;
		while (dsp->map.data[rows][cols++ + 1])
		{
			if (dsp->map.data[rows][cols] == '\n')
				break ;
			if ((rows == 0 || rows == dsp->map.rows - 1 || cols == 0)
				&& dsp->map.data[rows][cols] != '1')
				error_map("Map is not surrounded by walls", dsp);
			check_map_char(dsp, dsp->map.data[rows][cols], cols, rows);
		}
		if (cols == 0 && rows == dsp->map.rows - 1)
			break ;
		if (cols != dsp->map.cols)
			error_map("Map is not rectangular", dsp);
		if (dsp->map.data[rows][cols - 1] != '1')
			error_map("Map is not surrounded by walls", dsp);
	}
	if (!dsp->map.c_count)
		error_map("Map has no collectables", dsp);
}

void	check_map_name(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	i -= 4;
	if (ft_strncmp(file + i, ".ber", 4) != 0)
	{
		ft_putstr_fd("File must be in .ber\n", 2);
		exit(1);
	}
}

void	check_map_char(t_display *dsp, char c, int x, int y)
{
	if (c == 'C')
	{
		dsp->map.c_count++;
		add_collectable(dsp, x, y);
	}
	else if (c == 'P')
	{
		if (dsp->map.p_count > 0)
			error_map("Map has more than one player's starting position", dsp);
		dsp->map.p_count++;
		dsp->map.player.x = x;
		dsp->map.player.y = y;
	}
	else if (c == 'E')
	{
		if (dsp->map.e_count > 0)
			error_map("Map has more than one exit", dsp);
		dsp->map.e_count++;
		dsp->map.exit.x = x;
		dsp->map.exit.y = y;
	}
	else if (!ft_strchr("01CEP", c))
		error_map("Map has invalid character", dsp);
}
