/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:18:45 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/29 14:43:31 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_list	*variables(void)
{
	t_list	*var;

	var = (t_list *)malloc(sizeof(t_list));
	if (!var)
		return (NULL);
	var->left = 0;
	var->zero = 0;
	var->dot = -1;
	var->prefix = 0;
	var->space = 0;
	var->sign = 0;
	var->width = 0;
	return (&*var);
}

static const char	*dot_flag(const char *s, t_list *var)
{
	if (*s == '.')
		var->dot = 0;
	s++;
	if (ft_strchr("1234567890", *s))
		var->dot = ft_atoi(s);
	while (ft_strchr("1234567890", *s))
		s++;
	return (&*s);
}

static int	check_type(va_list args, const char *s, t_list *var)
{
	int	len;

	len = 0;
	if (*s == '.')
		s = dot_flag(s, var);
	if (*s == 'c')
		len = i_printchar(va_arg(args, int), var);
	else if (*s == 's')
		len = i_printstr(va_arg(args, char *), var);
	else if (*s == 'p')
		len = i_putaddress(va_arg(args, unsigned long long), var);
	else if (*s == 'd' || *s == 'i')
		len = i_putnbr(va_arg(args, int), var, 0, 0);
	else if (*s == 'u')
		len = i_putunsigned(va_arg(args, unsigned int), var);
	else if (*s == 'x' || *s == 'X')
		len = i_puthexa(va_arg(args, unsigned int), *s, var);
	else if (*s == '%')
		len = i_putchar('%');
	if (var->left == 1 && *s != '%')
		padding((var->width - len), var->zero);
	if (len > var->width || *s == '%')
		return (len);
	return (var->width);
}

static int	check_flags(va_list args, const char *s)
{
	t_list	*var;
	int		result;

	var = variables();
	while (ft_strchr("-0# +", *s))
	{
		if (*s == '-')
			var->left = 1;
		else if (*s == '0')
			var->zero = 1;
		else if (*s == '#')
			var->prefix = 1;
		else if (*s == ' ')
			var->space = 1;
		else if (*s == '+')
			var->sign = 1;
		s++;
	}
	if (ft_strchr("1234567890", *s))
		var->width = ft_atoi(s);
	while (ft_strchr("1234567890", *s))
		s++;
	result = check_type(args, s, var);
	free(var);
	return (result);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			len;

	len = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s != '%')
			len += i_putchar(*s);
		if (*s == '%' && *(s + 1) != '%')
		{
			s++;
			len += check_flags(args, s);
			while (ft_strchr("-0.# +123456789", *s))
				s++;
		}
		else if (*s == '%' && *(s + 1) == '%')
		{
			len += i_putchar(*s);
			s++;
		}
		s++;
	}
	va_end(args);
	return (len);
}
