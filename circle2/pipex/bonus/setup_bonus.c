/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:55:01 by aputri-a          #+#    #+#             */
/*   Updated: 2024/11/04 15:05:42 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	heredoc_setup(char **argv, int argc)
{
	int		pfd[2];
	pid_t	child_pid;

	if (pipe(pfd) == -1)
		error_handling("pipe");
	child_pid = fork();
	if (child_pid == -1)
		error_handling("fork");
	if (child_pid == 0)
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		close(pfd[1]);
		heredoc_input(argv);
		exit(0);
	}
	else
	{
		wait(0);
		close(pfd[1]);
		dup2(pfd[0], 0);
		close(pfd[0]);
		return (open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0666));
	}
}

void	heredoc_input(char **argv)
{
	char	*input;

	input = get_next_line(0);
	while (input)
	{
		if (ft_strncmp(input, argv[2], ft_strlen(argv[2])) == 0
			&& *(input + ft_strlen(argv[2])) == '\n')
		{
			free(input);
			exit(0);
		}
		ft_putstr_fd(input, 1);
		free(input);
		input = get_next_line(0);
	}
}

void	initialize_input(char *file, int i)
{
	int		fd;

	if (i == 2)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
			error_handling(file);
		if (dup2(fd, 0) == -1)
			error_handling("dup2");
		close(fd);
	}
}

void	pipe_loop(char *cmd, char **envp, int i, char **argv)
{
	int		pfd[2];
	pid_t	child_pid;

	if (pipe(pfd) == -1)
		error_handling("pipe");
	child_pid = fork();
	if (child_pid == -1)
		error_handling("fork");
	if (child_pid == 0)
	{
		initialize_input(argv[1], i);
		close(pfd[0]);
		if (dup2(pfd[1], 1) == -1)
			error_handling("dup2");
		close(pfd[1]);
		exec_cmds(cmd, envp);
	}
	else
	{
		waitpid(child_pid, NULL, WNOHANG);
		close(pfd[1]);
		if (dup2(pfd[0], 0))
			error_handling("dup2");
		close(pfd[0]);
	}
}
