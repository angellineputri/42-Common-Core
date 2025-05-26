/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:50:35 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/19 16:29:57 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_strlen(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += 2;
		n += 2000000000;
		n *= -1;
	}
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		len++;
	}
	len++;
	return (len);
}

static char	*fill(int n, char *str, int strlen)
{
	int	count;
	int	temp;
	int	i;

	i = 0;
	while (i < strlen)
	{
		count = 0;
		temp = n;
		while (temp / 10 > 0)
		{
			temp /= 10;
			count++;
		}
		while (strlen - i != count + 1)
			str[i++] = '0';
		if (strlen - i == count + 1)
			str[i++] = temp + '0';
		while (count--)
			temp *= 10;
		n -= temp;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	char	*str_ptr;
	int		strlen;

	strlen = int_strlen(n);
	str = (char *)malloc((strlen + 1) * sizeof(char));
	str_ptr = str;
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		*str_ptr++ = '-';
		*str_ptr++ = '2';
		n += 2000000000;
		n *= -1;
		strlen -= 2;
	}
	if (n < 0)
	{
		*str_ptr++ = '-';
		n *= -1;
		strlen--;
	}	
	str_ptr = fill (n, str_ptr, strlen);
	return (str);
}

/*
int	main()
{
	printf("%s\n", ft_itoa(-2147483648));
}
*/
