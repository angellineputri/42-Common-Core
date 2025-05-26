/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:17:37 by aputri-a          #+#    #+#             */
/*   Updated: 2024/06/09 16:34:22 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*joined;
	char	*ptr;

	if (!str1 || !str2)
		return (NULL);
	joined = (char *)malloc((ft_strlen(str1)
				+ ft_strlen(str2) + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	ptr = joined;
	while (*str1)
		*ptr++ = *str1++;
	while (*str2)
		*ptr++ = *str2++;
	*ptr = '\0';
	return (joined);
}

char	*ft_strdup(char *s, char **line)
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
