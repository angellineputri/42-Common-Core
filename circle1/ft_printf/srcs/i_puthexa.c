/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_puthexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:39:59 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/29 13:40:02 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	printhexa(unsigned int n, char c)
{
	char	*s;

	if (c == 'X')
		s = "0123456789ABCDEF";
	else
		s = "0123456789abcdef";
	if (n > 15)
		printhexa(n / 16, c);
	i_putchar(s[n % 16]);
}

static int	hexalen(unsigned int n)
{
	unsigned int	temp;
	int				len;

	len = 0;
	temp = n;
	while (temp > 15)
	{
		temp /= 16;
		len++;
	}
	len++;
	return (len);
}

static int	hx_flags(int len, t_list *var)
{
	int	dot_pad;

	if (var->dot > len)
		dot_pad = var->dot;
	else
		dot_pad = len;
	if (var->left == 0 && var->zero == 0)
		padding((var->width - dot_pad), var->zero);
	padding((var->dot - len), 1);
	if (var->left == 0 && var->zero == 1)
		padding((var->width - dot_pad), var->zero);
	return (len);
}

int	i_puthexa(unsigned int n, char c, t_list *var)
{
	int	len;

	len = hexalen(n);
	if (var->prefix == 1 && n != 0)
	{
		if (c == 'X')
			i_putstr("0X");
		if (c == 'x')
			i_putstr("0x");
		len += 2;
		var->prefix = 0;
	}
	if (var->dot == 0 && n == 0)
		return (hx_flags(0, var));
	if (var->dot != -1)
		var->zero = 0;
	else
		var->dot = 0;
	len = hx_flags(len, var);
	printhexa(n, c);
	if (var->dot > len)
		return (var->dot);
	return (len);
}
