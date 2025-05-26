NAME = push_swap

CHECKER = checker

SRC = initial_setup.c \
	helper_functions.c \
	stacka_setup.c \
	stackb_setup.c \
	operation_sp.c \
	operation_rotate.c \
	operation_rr.c \
	stack_helpers.c \
	check_group.c \
	search_group.c \
	solve.c \
	base_cases.c \
	last_digits_sort.c \
	lds_g12.c \
	lds_g34.c \
	one_digit_sort.c \
	ods_cleanup.c \
	two_digits_sort.c \
	td_move.c \
	tds_g3.c \
	tds_g14.c \
	first_half.c \
	fh_move.c \
	fh_last.c \

SRC_BONUS = gnl_bonus.c \
			gnl_utils_bonus.c \
			main_bonus.c \

SRC_MANDATORY = main.c \

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

OBJ_MANDATORY = $(SRC_MANDATORY:.c=.o)

HEAD = .

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar rcs

all: $(NAME)

bonus: $(CHECKER)

.c.o:
	$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@

$(NAME): $(OBJ_MANDATORY) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ_MANDATORY) $(OBJ)

$(CHECKER): $(OBJ_BONUS) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ_BONUS) $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_MANDATORY)
	$(RM) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(CHECKER)

re: fclean all

.PHONY = all clean fclean re bonus
