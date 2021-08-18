CC=gcc
C_FLAGS=-Wall -Wextra -Werror
NAME=push_swap
MAIN=push_swap.c
CHECKER=checker
BONUS=bonus_checker.c
LIBS=libft_stack/libft_stack.a \
	libft/libft.a
GNL=get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c
SRC=ps_solve_three.c \
	ps_init.c \
	ps_find_insert.c \
	ps_find_min.c \
	ps_rotate_stack.c \
	ps_sort_stack.c \
	ps_check_dup.c \
	ps_chunks.c \
	ps_solve_small.c \
	ps_solve_two.c \
	ps_solve_hun.c \
	ps_find_max.c \
	ps_solve_fhun.c \
	ps_check_stack.c \
	ps_parse_str.c

all:$(NAME)

$(NAME): $(SRC) $(MAIN)
	make -C libft
	make -C libft_stack
	$(CC) $(C_FLAGS) $^ $(LIBS) -o $@

clean:
	make -C libft clean
	make -C libft_stack clean

fclean:
	make -C libft fclean
	make -C libft_stack fclean
	rm -f $(NAME) $(CHECKER)

re:
	make fclean
	make $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(SRC) $(BONUS) $(GNL)
	make -C libft
	make -C libft_stack
	$(CC) $(C_FLAGS) $^ $(LIBS) -o $@ -D BUFFER_SIZE=1