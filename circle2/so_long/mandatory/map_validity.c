/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:46:17 by aputri-a          #+#    #+#             */
/*   Updated: 2024/10/22 00:00:56 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_valid_path(t_display *dsp)
{
	int	found;

	found = 0;
	copy_data(dsp);
	if (!check_exit_path(dsp, dsp->map.player.x, dsp->map.player.y))
		error_map("Invalid path to exit", dsp);
	copy_data(dsp);
	if (!check_collectable_path(dsp, dsp->map.player.x,
			dsp->map.player.y, &found))
		error_map("Invalid path to collectable", dsp);
	ft_free_2d(&dsp->map.data_copy);
}

int	check_exit_path(t_display *dsp, int x, int y)
{
	int	left;
	int	right;
	int	top;
	int	bot;

	if (x == dsp->map.exit.x && y == dsp->map.exit.y)
		return (1);
	if (x < 0 || x >= dsp->map.cols || y < 0 || y >= dsp->map.rows
		|| dsp->map.data_copy[y][x] == '1')
		return (0);
	dsp->map.data_copy[y][x] = '1';
	left = check_exit_path(dsp, x - 1, y);
	right = check_exit_path(dsp, x + 1, y);
	top = check_exit_path(dsp, x, y - 1);
	bot = check_exit_path(dsp, x, y + 1);
	if (left || right || top || bot)
		return (1);
	else
		return (0);
}

int	check_collectable_path(t_display *dsp, int x, int y, int *found)
{
	t_pos	*current;

	current = dsp->map.collectable;
	while (current != NULL)
	{
		if (current->found == 0 && x == current->x && y == current->y)
		{
			current->found = 1;
			(*found)++;
		}
		current = current->next;
	}
	if (x < 0 || x >= dsp->map.cols || y < 0 || y >= dsp->map.rows
		|| dsp->map.data_copy[y][x] == '1' || dsp->map.data_copy[y][x] == 'E')
		return (0);
	dsp->map.data_copy[y][x] = '1';
	check_collectable_path(dsp, x - 1, y, found);
	check_collectable_path(dsp, x + 1, y, found);
	check_collectable_path(dsp, x, y - 1, found);
	check_collectable_path(dsp, x, y + 1, found);
	return ((*found) == dsp->map.c_count);
}

void	copy_data(t_display *dsp)
{
	int		i;
	char	**map;

	if (dsp->map.data_copy)
		ft_free_2d(&dsp->map.data_copy);
	map = malloc(sizeof(char *) * (dsp->map.rows + 1));
	if (!map)
	{
		ft_free_2d(&dsp->map.data);
		ft_error_handling("malloc");
	}
	i = 0;
	while (dsp->map.data[i])
	{
		map[i] = ft_strdup(dsp->map.data[i]);
		if (!map[i++])
		{
			ft_free_2d(&dsp->map.data);
			ft_free_2d(&map);
			ft_error_handling("ft_strdup");
		}
	}
	map[i] = NULL;
	dsp->map.data_copy = map;
}
