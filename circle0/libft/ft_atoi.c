/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:59:00 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/17 17:47:21 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*
int	main()
{
	const char	str[50] = " \n \v \f \r   \t +a829i89";
	printf("original atoi :%d\n", atoi(str));
	printf("ft_atoi       :%d\n", ft_atoi(str));
}
*/
