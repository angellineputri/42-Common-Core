/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:28:29 by aputri-a          #+#    #+#             */
/*   Updated: 2024/06/09 16:34:29 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*read_file(int fd, char **main_buffer);
int		find_newline(char **buffer, int fd);
void	save_remainder(char **buffer, char *remainder);
char	*fill_line(char **buffer, int len);
int		ft_strlen(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strdup(char *s, char **line);
int		line_len(char *buffer);
void	ft_reset(char **buffer);
void	ft_reset(char **buffer);

#endif
