NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = push_swap.c   push.c   swap.c   rotate.c   reverse_rotate.c \
      functions_utiles.c   lst_utiles.c   split.c   check_args.c \
      sort1.c  sort2.c  algo_sort.c  push_to_a.c  push_to_b.c  push_to_a_utiles.c\

OBJ = $(SRC:.c=.o)

CHECKER_BONUS = checker

SRC_BONUS = checker_bonus/push_swap_bonus.c \
            checker_bonus/push_bonus.c \
            checker_bonus/swap_bonus.c \
            checker_bonus/rotate_bonus.c \
            checker_bonus/reverse_rotate_bonus.c \
            checker_bonus/functions_utiles_bonus.c \
            checker_bonus/lst_utiles_bonus.c \
            checker_bonus/split_bonus.c \
            checker_bonus/check_args_bonus.c \
            checker_bonus/get_next_line.c \
            checker_bonus/get_next_line_utiles.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(CHECKER_BONUS)

$(CHECKER_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(CHECKER_BONUS)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(CHECKER_BONUS)

re: fclean all