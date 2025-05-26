/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:55:18 by aputri-a          #+#    #+#             */
/*   Updated: 2024/11/04 14:26:29 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	exec_cmds(char *arg, char **envp)
{
	char	**cmds;
	char	*path;

	if (arg[0] == '\0')
		return ;
	cmds = cmds_handler(arg);
	if (cmds && cmds[0] && ft_strchr(cmds[0], '/'))
		path = available_path(&cmds);
	else
		path = find_path_helper(&cmds, envp, arg);
	if (!path)
		return ;
	execve(path, cmds, envp);
	free_2d(&cmds);
	if (path)
		free(path);
	error_handling("execve");
}
