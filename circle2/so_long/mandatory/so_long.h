/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:04:04 by aputri-a          #+#    #+#             */
/*   Updated: 2024/10/22 01:08:39 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

# ifndef SIZE
#  define SIZE 32
# endif

typedef struct s_pos
{
	int				x;
	int				y;
	int				found;
	struct s_pos	*next;
}				t_pos;

typedef struct s_img
{
	void	*img;
	int		img_height;
	int		img_width;
}				t_img;

typedef struct s_map
{
	char	**data;
	char	**data_copy;
	int		cols;
	int		rows;
	int		p_count;
	int		e_count;
	int		c_count;
	t_pos	*collectable;
	t_pos	player;
	t_pos	exit;
}				t_map;

typedef struct s_display
{
	t_map	map;
	void	*mlx;
	void	*window;
	int		move;
	t_img	block;
	t_img	cat;
	t_img	key;
	t_img	gate;
	t_img	bg;
}				t_display;

// from map_input.c
void	error_map(char *msg, t_display *dsp);
void	assign_map(t_display *dsp, char *file);
void	check_map(t_display *dsp);
void	check_map_name(char *file);
void	check_map_char(t_display *dsp, char c, int x, int y);

// from map_validity.c
void	check_valid_path(t_display *dsp);
int		check_exit_path(t_display *dsp, int x, int y);
int		check_collectable_path(t_display *dsp, int x, int y, int *found);
void	copy_data(t_display *dsp);

// from map_utils.c
void	count_rows(t_display *dsp, char *file);
void	count_cols(t_display *dsp);
void	add_collectable(t_display *dsp, int x, int y);
void	free_collectable(t_display *dsp);
char	**fill_map(t_display *dsp, int fd);

// from image_render.c
void	render(t_display *dsp);
void	file_to_img(t_display *dsp);
void	show_counter(t_display *dsp);

// from moves.c
int		handle_keyboard_input(int keysym, t_display *dsp);
void	move_player(int x, int y, t_display *dsp);
void	renew(char new_data, void *new_img, t_display *dsp);

// from cleanup.c
int		exit_program(t_display *dsp, int ex);
void	exit_status(t_display *dsp, int *ex);
int		exit_close_win(t_display *dsp);

#endif