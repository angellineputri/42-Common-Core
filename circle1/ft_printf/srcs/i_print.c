/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:26:29 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/28 15:13:36 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	i_putchar(int c)
{
	write (1, &c, sizeof(char));
	return (1);
}

int	i_printchar(int c, t_list *var)
{
	if (var->left == 0)
		padding((var->width - 1), var->zero);
	write (1, &c, sizeof(char));
	return (1);
}

int	i_putstr(char *s)
{
	write (1, s, (sizeof(char) * ft_strlen(s)));
	return (ft_strlen(s));
}

int	i_printstr(char *s, t_list *var)
{
	int	len;
	int	pad;

	len = ft_strlen(s);
	if (!s)
	{
		pad = 6;
		if (var->dot >= 0 && var->dot < 6)
			pad = 0;
		if (var->left == 0)
			padding((var->width - pad), var->zero);
		if (var->dot == -1 || pad == 6)
		{
			write (1, "(null)", (sizeof(char) * 6));
			return (6);
		}
		return (0);
	}
	if (var->dot != -1 && var->dot < len)
		len = var->dot;
	if (var->left == 0)
		padding((var->width - len), var->zero);
	write (1, s, (sizeof(char) * len));
	return (len);
}
