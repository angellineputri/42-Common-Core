/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:59:35 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/28 15:00:33 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	c %= 256;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	converted;

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

void	padding(int len, int chr)
{
	if (len <= 0)
		return ;
	if (chr == 0)
		while (len--)
			i_putchar(' ');
	if (chr == 1)
		while (len--)
			i_putchar('0');
}
