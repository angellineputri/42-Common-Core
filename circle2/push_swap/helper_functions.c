/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:31:03 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/24 13:53:30 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *num)
{
	int		i;
	int		sign;
	long	converted;

	i = 0;
	sign = -1;
	converted = 0;
	if (num[i] == '-')
		i++;
	else
		sign = 1;
	while (num[i] >= '0' && num[i] <= '9')
	{
		if (sign == -1 && converted == 214748364 && num[i] == '8')
		{
			if (num[i + 1] == '\0')
				return (-2147483648);
			return (0);
		}
		converted = (converted * 10) + (num[i] - '0');
		i++;
	}
	if (num[i] != '\0' || converted < -2147483648 || converted > 2147483647)
		return (0);
	return ((int)sign * converted);
}

int	ft_strchr(int *arr, int num, int size)
{
	int	i;

	i = 0;
	size--;
	while (size)
	{
		if (arr[i] == num)
			return (1);
		size--;
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	quaternary_len(int num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		num /= 4;
		len++;
	}
	return (len);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
