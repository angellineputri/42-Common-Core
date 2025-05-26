/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:01:09 by aputri-a          #+#    #+#             */
/*   Updated: 2025/01/18 17:12:14 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write (fd, s, (sizeof(char) * len));
}

long	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	converted;

	i = 0;
	sign = 1;
	converted = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		converted = (converted * 10) + (nptr[i] - '0');
		i++;
	}
	return (sign * converted);
}

int	ft_err_return(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	destroy_mutex_arr(pthread_mutex_t **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		pthread_mutex_destroy(&(*arr)[i++]);
	free(*arr);
}
