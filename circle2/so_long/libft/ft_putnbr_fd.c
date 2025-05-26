/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:40:43 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/30 13:28:04 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(int n)
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

static void	ft_putchar(int n, int fd)
{
	n += '0';
	write (fd, &n, sizeof(char));
}

static void	write_n(int n, int fd, int len)
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
