CC = cc
CFLAGS += -Wall -Wextra -Werror

SRC = ./srcs/ft_printf.c ./srcs/ft_helper.c ./srcs/i_print.c ./srcs/i_putnbr.c ./srcs/i_putunsigned.c ./srcs/i_putaddress.c ./srcs/i_puthexa.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

HEAD = ./includes/

RM = rm -f

AR = ar rcs

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(NAME)

.PHONY = all clean fclean re bonus
