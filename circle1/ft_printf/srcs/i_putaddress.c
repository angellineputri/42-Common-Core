/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_putaddress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:31:44 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/29 13:31:45 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	printadr(unsigned long long adr)
{
	char	*s;

	s = "0123456789abcdef";
	if (adr > 15)
		printadr(adr / 16);
	else
		i_putstr("0x");
	i_putchar(s[adr % 16]);
}

int	i_putaddress(unsigned long long adr, t_list *var)
{
	int					len;
	unsigned long long	temp;

	len = 0;
	temp = adr;
	if (adr == 0)
	{
		if (var->left == 0)
			padding((var->width - 5), var->zero);
		i_putstr("(nil)");
		return (5);
	}
	while (temp > 15)
	{
		temp /= 16;
		len += 1;
	}
	len += 3;
	if (var->left == 0)
		padding((var->width - len), var->zero);
	printadr(adr);
	return (len);
}
