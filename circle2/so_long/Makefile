NAME = so_long
NAME_BONUS = so_long_bonus

LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a

SRCS = get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	mandatory/main.c \
	mandatory/map_input.c \
	mandatory/map_validity.c \
	mandatory/map_utils.c \
	mandatory/img_render.c \
	mandatory/moves.c \
	mandatory/cleanup.c \

SRCS_BONUS = get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	bonus/main_bonus.c \
	bonus/map_input_bonus.c \
	bonus/map_validity_bonus.c \
	bonus/map_utils_bonus.c \
	bonus/mlx_utils_bonus.c \
	bonus/setup_bonus.c \
	bonus/render_img_bonus.c \
	bonus/render_char_bonus.c \
	bonus/render_patrol_bonus.c \
	bonus/input_handler_bonus.c \
	bonus/update_bonus.c \
	bonus/destroy_img_bonus.c \
	bonus/cleanup_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./mandatory
CFLAGS_BONUS = -Wall -Wextra -Werror -I./bonus

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Iminilibx-linux -O3 -c $< -o $@

all: $(NAME)

$(LIBFT):
	$(MAKE) bonus -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS)
	$(CC) $(CFLAGS_BONUS) $(OBJS_BONUS) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -L$(LIBFT_DIR) -lft -o $(NAME_BONUS)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus