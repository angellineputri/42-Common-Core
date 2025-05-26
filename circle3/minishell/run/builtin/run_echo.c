/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfasius <dfasius@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 07:46:41 by dfasius           #+#    #+#             */
/*   Updated: 2024/12/19 08:11:35 by dfasius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	echo_newline(char *str)
{
	int	i;

	i = 1;
	if (str[0] && str[0] != '-')
		return (0);
	while (str[i])
	{
		if (str[i] == 'n')
			i++;
		else
			return (0);
	}
	return (1);
}

int	run_echo(char **dir)
{
	int	no_newline;
	int	i;

	i = 1;
	no_newline = 0;
	while (dir[i] && echo_newline(dir[i]))
	{
		no_newline = 1;
		i++;
	}
	while (dir[i])
	{
		ft_putstr_fd(dir[i], 1);
		if (dir[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!no_newline)
		ft_putstr_fd("\n", 1);
	return (0);
}
