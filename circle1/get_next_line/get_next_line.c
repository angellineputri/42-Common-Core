/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:28:07 by aputri-a          #+#    #+#             */
/*   Updated: 2024/06/09 16:49:46 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char **main_buffer)
{
	char	*buffer;
	int		read_size;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(*main_buffer);
		*main_buffer = NULL;
		return (NULL);
	}
	read_size = read(fd, buffer, BUFFER_SIZE);
	if (read_size == -1)
	{
		free(buffer);
		free(*main_buffer);
		*main_buffer = NULL;
		return (NULL);
	}
	buffer[read_size] = '\0';
	return (buffer);
}

int	find_newline(char **buffer, int fd)
{
	char	*new_buffer;
	char	*joined;

	while (line_len(*buffer) == -1)
	{
		new_buffer = read_file(fd, buffer);
		if (!new_buffer)
			return (-1);
		if (new_buffer[0] == '\0')
		{
			free(new_buffer);
			return (ft_strlen(*buffer));
		}
		joined = ft_strjoin(*buffer, new_buffer);
		if (!joined)
		{
			ft_reset(buffer);
			free(new_buffer);
			return (-1);
		}
		free(new_buffer);
		free(*buffer);
		*buffer = joined;
	}
	return (line_len(*buffer));
}

void	save_remainder(char **buffer, char *remainder)
{
	if (!remainder)
		ft_reset(buffer);
	else
	{
		free(*buffer);
		*buffer = remainder;
	}
}

char	*fill_line(char **buffer, int len)
{
	char	*line;
	char	*remainder;
	int		i;

	i = 0;
	line = (char *)malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while ((*buffer)[i] && (*buffer)[i] != '\n')
	{
		line[i] = (*buffer)[i];
		i++;
	}
	if ((*buffer)[i] == '\n')
	{
		line[i] = (*buffer)[i];
		i++;
	}
	line[i] = '\0';
	remainder = ft_strdup(*buffer + i, &line);
	save_remainder(&(*buffer), remainder);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096] = {NULL};
	char		*line;
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = read_file(fd, buffer);
		if (!buffer[fd] || buffer[fd][0] == '\0')
		{
			ft_reset(&buffer[fd]);
			return (NULL);
		}
	}
	len = find_newline(&buffer[fd], fd);
	if (len == -1 || len == 0)
		return (NULL);
	line = fill_line(&buffer[fd], len);
	if (!line)
	{
		ft_reset(&buffer[fd]);
		return (NULL);
	}
	return (line);
}
