/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:28:51 by aputri-a          #+#    #+#             */
/*   Updated: 2024/11/04 14:19:14 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

// from pipex.c
void	process_child(char **argv, char **envp, int *pfd);
void	process_parent(char **argv, char **envp, int *pfd);
void	exec_cmds(char *arg, char **envp);
char	*find_path_helper(char ***cmds, char **envp, char *arg);

// from cmds.c
char	**cmds_handler(char *arg);
char	*fill_cmd(char **arg, int sq, int dq, int cb);
char	*find_path(char ***cmds, char **envp);
char	*cmd_path(char ***allpaths, char ***cmds, int i);
char	*available_path(char ***cmds);

// from err.c
void	error_handling(char *msg);
void	error_command(char ***allpaths, char ***cmds);
void	free_2d(char ***arr);

#endif