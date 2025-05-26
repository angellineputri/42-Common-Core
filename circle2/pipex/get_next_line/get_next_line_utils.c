/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:17:37 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/30 16:18:47 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_gnl(char *s, char **line)
{
	int		i;
	char	*dup;

	i = 0;
	if (s[0] == '\0')
		return (NULL);
	dup = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dup)
	{
		free(*line);
		*line = NULL;
		return (NULL);
	}
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	line_len(char *buffer)
{
	int	len;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		return (len + 1);
	return (-1);
}

void	ft_reset(char **buffer)
{
	if (*buffer)
		free(*buffer);
	*buffer = NULL;
}
