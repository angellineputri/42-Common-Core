/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_putunsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:51:32 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/28 14:59:07 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	uslen(unsigned int n)
{
	int	len;

	len = 0;
	while (n / 10 > 0)
	{
		n /= 10;
		len++;
	}
	len++;
	return (len);
}

static void	print_n(unsigned int n, int len)
{
	char	*nbr_arr;
	char	*ptr;

	if (n == 0)
	{
		i_putchar(0 + '0');
		return ;
	}
	nbr_arr = (char *)malloc(sizeof(char) * (len + 1));
	ptr = nbr_arr;
	if (!nbr_arr)
		return ;
	nbr_arr[len] = '\0';
	while (len--)
	{
		nbr_arr[len] = (n % 10) + '0';
		n /= 10;
	}
	while (*nbr_arr)
	{
		i_putchar(*nbr_arr);
		nbr_arr++;
	}
	free(ptr);
	return ;
}

static int	us_flags(int len, t_list *var)
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

int	i_putunsigned(unsigned int n, t_list *var)
{
	int	len;

	len = uslen(n);
	if (var->dot == 0 && n == 0)
		return (us_flags(0, var));
	if (var->dot != -1)
		var->zero = 0;
	else
		var->dot = 0;
	len = us_flags(len, var);
	print_n(n, len);
	if (var->dot > len)
		return (var->dot);
	return (len);
}
