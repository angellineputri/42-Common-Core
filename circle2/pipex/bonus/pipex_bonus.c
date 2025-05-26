/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:53:26 by aputri-a          #+#    #+#             */
/*   Updated: 2024/11/04 15:11:17 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		fd_out;

	if (argc < 5 || (!ft_strcmp(argv[1], "here_doc") && argc < 6))
		return (ft_putstr_fd(
				"./pipex infile cmd1 cmd2 ... cmdn outfile\n", 2),
			ft_putstr_fd("./pipex here_doc LIMITER cmd1 \
				... cmdn file\n", 2), 1);
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		i = 3;
		fd_out = heredoc_setup(argv, argc);
	}
	else
	{
		i = 2;
		fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	}
	if (fd_out == -1)
		error_handling(argv[argc - 1]);
	if (dup2(fd_out, 1) == -1)
		error_handling("dup2");
	close(fd_out);
	while (i++ < argc - 2)
		pipe_loop(argv[i - 1], envp, i - 1, argv);
	exec_cmds(argv[i - 1], envp);
}

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
