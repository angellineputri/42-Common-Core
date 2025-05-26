/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:36:26 by aputri-a          #+#    #+#             */
/*   Updated: 2024/11/04 13:59:42 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**cmds_handler(char *arg)
{
	char	**cmds;
	int		single_quote;
	int		double_quote;
	int		cbracket;
	int		i;

	single_quote = 0;
	double_quote = 0;
	cbracket = 0;
	i = 0;
	cmds = malloc(sizeof(char *) * (ft_strlen(arg) + 1));
	if (!cmds)
		return (error_handling("malloc"), NULL);
	while (*arg)
	{
		while (*arg && *arg == ' ')
			arg++;
		if (*arg && *arg != ' ')
		{
			cmds[i++] = fill_cmd(&arg, single_quote, double_quote, cbracket);
			if (!cmds[i - 1])
				return (free_2d(&cmds), error_handling("malloc"), NULL);
		}
	}
	return (cmds[i] = NULL, cmds);
}

char	*fill_cmd(char **arg, int sq, int dq, int cb)
{
	char	*arr;
	int		j;

	j = 0;
	arr = malloc(sizeof(char) * (ft_strlen(*arg) + 1));
	if (!arr)
		return (NULL);
	while ((**arg) && ((**arg) != ' ' || sq || dq || cb))
	{
		if (!cb && !dq && (**arg) == '\'')
			sq = !sq;
		else if (!cb && !sq && (**arg) == '"')
			dq = !dq;
		else if ((**arg) == '\\')
		{
			(*arg)++;
			arr[j++] = (**arg);
		}
		else
			arr[j++] = (**arg);
		if ((**arg) == '{' || (**arg) == '}')
			cb = !cb;
		(*arg)++;
	}
	return (arr[j] = '\0', arr);
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
