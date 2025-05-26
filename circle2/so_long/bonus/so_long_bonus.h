/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 01:04:33 by aputri-a          #+#    #+#             */
/*   Updated: 2024/10/25 16:11:55 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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

typedef enum s_cases
{
	IDLE,
	RIGHT,
	LEFT,
	UP,
	DOWN,
	RHW,
	LHW,
	UHW,
	DHW,
}			t_cases;

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
	void	*mlx;
	void	*window;
	t_pos	initial;
	t_map	map;
	int		move;
	int		frame;
	t_cases	cases;
	void	*block;
	void	*gate;
	void	*key;
	void	*bg;
	void	*lightkey;
	void	*camo;
	void	*camolight;
	void	*light;
	void	*cat[5][8];
	int		width;
	int		height;
	int		patrol;
	int		patrol_frame;
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

// from mlx_utils.c
void	*load_img(t_display *dsp, char *path);
void	put_img(t_display *dsp, void *img, int x, int y);

// from setup.c
void	setup(t_display *dsp);
void	setup_char_idle(t_display *dsp);
void	setup_char_move(t_display *dsp);

// from render_img.c
void	render(t_display *dsp);
void	render_map(t_display *dsp);
void	*decide_key(t_display *dsp, int x, int y);
void	show_counter(t_display *dsp);

// from render_char.c
void	render_char(t_display *dsp);
void	render_hit_side(t_display *dsp);
void	render_hit_vertical(t_display *dsp);
void	renew(t_display *dsp, int x, int y);

// from render_patrol.c
void	render_patrol(t_display *dsp);
void	put_light(t_display *dsp, int x, int y, int camo);

// from input_handler.c
int		input_handler(int keysym, t_display *dsp);
void	move_decider(int x, int y, t_display *dsp, t_cases direction);
void	player_hit(t_display *dsp);
void	collect(t_display *dsp, int x, int y);
int		key_release(int keysym, t_display *dsp);

// from update.c
int		update(t_display *dsp);
int		max_frame(t_display *dsp);

// from destroy_img.c
void	destroy_img(t_display *dsp);
void	destroy_char_idle(t_display *dsp);
void	destroy_char_side(t_display *dsp);
void	destroy_char_vertical(t_display *dsp);

// from cleanup.c
int		exit_program(t_display *dsp, int ex);
void	exit_status(t_display *dsp, int *ex);
int		exit_close_win(t_display *dsp);

#endif