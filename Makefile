CC=gcc
C_FLAGS=-Wall -Werror -Wextra
NAME=pipex
LIBS=libft/libft.a
GNL_FLAG=-D BUFFER_SIZE=1
GNL= ft_get_next_line/get_next_line.c \
	ft_get_next_line/get_next_line_utils.c
SRC=pipex.c	\
	px_err_msg.c \
	px_check_command.c \
	px_split_res.c \
	px_fork.c

all:$(NAME)

$(NAME): $(SRC) $(GNL)
	make -C libft
	$(CC) $(C_FLAGS) $^ $(GNL_FLAG) $(LIBS) -o $@

clean:
	make -C libft clean

fclean:
	make -C libft fclean
	rm -f $(NAME)

re:
	make fclean
	make $(NAME)


