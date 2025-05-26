/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:30:40 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/30 18:10:28 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_handling(char *msg)
{
	perror(msg);
	exit(1);
}

void	error_command(char ***allpaths, char ***cmds)
{
	ft_putstr_fd((*cmds)[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	if (allpaths)
		free_2d(allpaths);
	if (cmds)
		free_2d(cmds);
	exit(127);
}

void	free_2d(char ***arr)
{
	int	i;

	i = 0;
	while ((*arr) && (*arr)[i])
	{
		free((*arr)[i]);
		i++;
	}
	if (arr)
		free(*arr);
}
