/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:29:27 by aputri-a          #+#    #+#             */
/*   Updated: 2024/10/25 16:12:40 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_rows(t_display *dsp, char *file)
{
	char	*line;
	int		fd;
	int		end;

	end = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error_handling(file);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n' && end == 0)
			dsp->map.rows++;
		else if (line[0] != '\n' && end == 1)
			end = -1;
		else if (line[0] == '\n' && end != -1)
			end = 1;
		free(line);
		line = get_next_line(fd);
	}
	if (!dsp->map.rows)
		error_map("Map is nothing", dsp);
	if (end == -1)
		error_map("Map is not rectangular", dsp);
	close(fd);
}

void	count_cols(t_display *dsp)
{
	while (dsp->map.data && dsp->map.data[0]
		&& dsp->map.data[0][dsp->map.cols]
		&& dsp->map.data[0][dsp->map.cols] != '\n')
	{
		dsp->map.cols++;
	}
}

char	**fill_map(t_display *dsp, int fd)
{
	char	**map;
	char	*line;
	int		i;

	map = malloc(sizeof(char *) * (dsp->map.rows + 1));
	if (!map)
		ft_error_handling("malloc");
	i = 0;
	line = get_next_line(fd);
	if (!line)
		ft_error_handling("get_next_line");
	while (line)
	{
		if (i >= dsp->map.rows)
			free(line);
		else
			map[i++] = line;
		line = get_next_line(fd);
		if (!line && i < dsp->map.rows)
		{
			ft_free_2d(&map);
			ft_error_handling("get_next_line");
		}
	}
	return (map[i] = NULL, map);
}

void	add_collectable(t_display *dsp, int x, int y)
{
	t_pos	*new;
	t_pos	*current;

	new = malloc(sizeof(t_pos));
	if (!new)
	{
		ft_free_2d(&dsp->map.data);
		free_collectable(dsp);
		ft_error_handling("malloc");
	}
	new->x = x;
	new->y = y;
	new->found = 0;
	new->next = NULL;
	if (dsp->map.collectable == NULL)
		dsp->map.collectable = new;
	else
	{
		current = dsp->map.collectable;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}

void	free_collectable(t_display *dsp)
{
	t_pos	*current;
	t_pos	*next;

	current = dsp->map.collectable;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	dsp->map.collectable = NULL;
}
