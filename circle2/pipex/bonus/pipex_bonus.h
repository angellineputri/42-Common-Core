/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:53:38 by aputri-a          #+#    #+#             */
/*   Updated: 2024/11/04 14:28:12 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

// from pipex_bonus.c
int		heredoc_setup(char **argv, int argc);
void	heredoc_input(char **argv);
void	initialize_input(char *file, int i);
void	pipe_loop(char *cmd, char **envp, int i, char **argv);

// from cmds_bonus.c
char	**cmds_handler(char *arg);
char	*fill_cmd(char **arg, int sq, int dq, int cb);
void	exec_cmds(char *arg, char **envp);

// from path_bonus.c
char	*find_path_helper(char ***cmds, char **envp, char *arg);
char	*find_path(char ***cmds, char **envp);
char	*cmd_path(char ***allpaths, char ***cmds, int i);
char	*available_path(char ***cmds);

// from err_bonus.c
void	error_handling(char *msg);
void	error_command(char ***allpaths, char ***cmds);
void	free_2d(char ***arr);

#endif