/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:25:23 by aputri-a          #+#    #+#             */
/*   Updated: 2024/11/04 14:29:12 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*find_path_helper(char ***cmds, char **envp, char *arg)
{
	if (!envp || !envp[0])
	{
		free_2d(cmds);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": command not found\n", 2);
		exit (126);
	}
	if (!(*cmds) || !(*cmds)[0])
	{
		if ((*cmds))
			free_2d(cmds);
		return (NULL);
	}
	return (find_path(cmds, envp));
}

char	*find_path(char ***cmds, char **envp)
{
	char	*path;
	char	**allpaths;
	int		i;

	i = 0;
	while (envp[i++])
	{
		if (ft_strnstr(envp[i - 1], "PATH=", 5))
			path = ft_strnstr(envp[i - 1], "PATH=", 5);
	}
	allpaths = ft_split(path + 5, ':');
	if (!allpaths)
	{
		free_2d(cmds);
		error_handling("ft_split");
	}
	i = 0;
	while (allpaths[i++])
	{
		path = cmd_path(&allpaths, cmds, i - 1);
		if (access(path, X_OK) == 0)
			return (free_2d(&allpaths), path);
		free(path);
	}
	return (error_command(&allpaths, cmds), NULL);
}

char	*cmd_path(char ***allpaths, char ***cmds, int i)
{
	char	*path;
	char	*final;

	path = ft_strjoin((*allpaths)[i], "/");
	if (!path)
	{
		free_2d(allpaths);
		free_2d(cmds);
		error_handling("ft_strjoin");
	}
	final = ft_strjoin(path, (*cmds)[0]);
	free(path);
	if (!final)
	{
		free_2d(allpaths);
		free_2d(cmds);
		error_handling("ft_strjoin");
	}
	return (final);
}

char	*available_path(char ***cmds)
{
	char	*path;

	path = (*cmds)[0];
	if (access(path, X_OK) != 0)
	{
		if (access(path, F_OK) != 0)
			error_command(NULL, cmds);
		else
		{
			ft_putstr_fd((*cmds)[0], 2);
			ft_putstr_fd(": command found but not executable\n", 2);
			free_2d(cmds);
			exit (126);
		}
	}
	return (path);
}
