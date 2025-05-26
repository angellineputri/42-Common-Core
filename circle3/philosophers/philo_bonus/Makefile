NAME = philo_bonus

SRCS = philo_bonus.c \
	philo_libft_bonus.c \
	init_sml_bonus.c \
	init_philos_bonus.c \
	simulation_bonus.c \
	philo_life_bonus.c \
	philo_utils_bonus.c \
	exit_bonus.c \
	
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
