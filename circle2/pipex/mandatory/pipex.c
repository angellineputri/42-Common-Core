/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:30:38 by aputri-a          #+#    #+#             */
/*   Updated: 2024/11/04 15:46:42 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		pfd[2];
	pid_t	child_pid;

	if (argc != 5)
		return (ft_putstr_fd("./pipex infile cmd1 cmd2 outfile\n", 2), 1);
	if (pipe(pfd) == -1)
		error_handling("pipe");
	child_pid = fork();
	if (child_pid == -1)
		error_handling("fork");
	if (child_pid == 0)
		process_child(argv, envp, pfd);
	process_parent(argv, envp, pfd);
	return (0);
}

void	process_child(char **argv, char **envp, int *pfd)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_handling(argv[1]);
	close(pfd[0]);
	if (dup2(fd, 0) == -1)
		error_handling("dup2");
	if (dup2(pfd[1], 1) == -1)
		error_handling("dup2");
	close(pfd[1]);
	close(fd);
	exec_cmds(argv[2], envp);
}

void	process_parent(char **argv, char **envp, int *pfd)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		error_handling(argv[4]);
	close(pfd[1]);
	if (dup2(pfd[0], 0) == -1)
		error_handling("dup2");
	if (dup2(fd, 1) == -1)
		error_handling("dup2");
	close(pfd[0]);
	close(fd);
	exec_cmds(argv[3], envp);
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
