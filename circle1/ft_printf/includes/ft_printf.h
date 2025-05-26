/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:19:46 by aputri-a          #+#    #+#             */
/*   Updated: 2024/05/28 15:14:11 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int	left;
	int	zero;
	int	prefix;
	int	space;
	int	sign;
	int	dot;
	int	width;
}		t_list;

int		ft_printf(const char *s, ...);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
int		ft_atoi(const char *nptr);
void	padding(int len, int chr);
int		i_putchar(int c);
int		i_printchar(int c, t_list *var);
int		i_putstr(char *s);
int		i_printstr(char *s, t_list *var);
int		i_putnbr(long int n, t_list *var, int len, int ret_len);
int		i_putunsigned(unsigned int n, t_list *var);
int		i_putaddress(unsigned long long adr, t_list *var);
int		i_puthexa(unsigned int n, char c, t_list *var);

#endif
