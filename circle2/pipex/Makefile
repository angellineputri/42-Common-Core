NAME = pipex
NAME_BONUS = pipex_bonus

LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a

SRCS = mandatory/pipex.c \
	mandatory/cmds.c \
	mandatory/err.c \

SRCS_BONUS = bonus/pipex_bonus.c \
	bonus/setup_bonus.c \
	bonus/cmds_bonus.c \
	bonus/path_bonus.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./mandatory
CFLAGS_BONUS = -Wall -Wextra -Werror -I./bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT):
	$(MAKE) bonus -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS)
	$(CC) $(CFLAGS_BONUS) $(OBJS_BONUS) -L$(LIBFT_DIR) -lft -o $(NAME_BONUS)

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
