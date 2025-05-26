/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:41:44 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/28 14:51:06 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

static void	print_nbr(int n, int len)
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
			i_putchar('0');
			i++;
		}
		i_putchar(temp + '0');
		while (count--)
			temp *= 10;
		n -= temp;
		i++;
	}
}

static int	nbr_flags(int n, int ret_len, t_list *var)
{
	int	minus;
	int	dot_pad;

	minus = 0;
	if (var->dot > ret_len)
		dot_pad = var->dot;
	else
		dot_pad = ret_len;
	if (n < 0)
		minus++;
	if (var->left == 0 && var->zero == 0)
		padding((var->width - dot_pad
				- var->space - minus), var->zero);
	if (n >= 0 && var->sign == 1)
		i_putchar('+');
	if (n >= 0 && var->space == 1)
		i_putchar(' ');
	if (n < 0)
		i_putchar('-');
	padding((var->dot - ret_len), 1);
	if (var->left == 0 && var->zero == 1)
		padding((var->width - dot_pad - minus), var->zero);
	if (var->dot > ret_len)
		return (var->dot);
	return (ret_len);
}

int	i_putnbr(long int n, t_list *var, int len, int ret_len)
{
	len = nbrlen(n);
	if (var->dot == 0 && n == 0)
		return (nbr_flags(n, 0, var));
	if (var->dot != -1)
		var->zero = 0;
	else
		var->dot = 0;
	ret_len = nbr_flags(n, len, var);
	if (n >= 0 && (var->space == 1 || var->sign == 1))
		ret_len++;
	if (n == -2147483648)
	{
		i_putchar('2');
		n += 2000000000;
		n *= -1;
		len--;
		ret_len++;
	}
	if (n < 0)
	{
		ret_len++;
		n *= -1;
	}
	print_nbr(n, len);
	return (ret_len);
}
