/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:40:43 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/19 16:36:35 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbrlen(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		n += 2000000000;
		n *= -1;
		len++;
	}
	if (n < 0)
		n *= -1;
	while (n / 10 > 0)
	{
		n /= 10;
		len++;
	}
	len++;
	return (len);
}

void	ft_putchar(int n, int fd)
{
	n += '0';
	write (fd, &n, sizeof(char));
}

void	write_n(int n, int fd, int len)
{
	int	temp;
	int	count;
	int	i;

	i = 0;
	while (i < len)
	{
		count = 0;
		temp = n;
		while (temp / 10 > 0)
		{
			temp /= 10;
			count++;
		}
		while (len - i != count + 1)
		{
			write (fd, "0", sizeof(char));
			i++;
		}
		ft_putchar(temp, fd);
		while (count--)
			temp *= 10;
		n -= temp;
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	len;

	len = nbrlen(n);
	if (n == -2147483648)
	{
		write (fd, "-2", (sizeof(char) * 2));
		n += 2000000000;
		n *= -1;
		len--;
	}
	if (n < 0)
	{
		write (fd, "-", sizeof(char));
		n *= -1;
	}
	write_n(n, fd, len);
}

/*
int	main()
{
	ft_putnbr_fd(-2147483648, 1);
}
*/
