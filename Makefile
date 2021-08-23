CC=gcc
C_FLAGS=-Wall -Werror -Wextra
NAME=pipex
LIBS=libft/libft.a
GNL_FLAG=-D BUFFER_SIZE=1
GNL= ft_get_next_line/get_next_line.c \
	ft_get_next_line/get_next_line_utils.c
MAIN=pipex.c
SRC=px_err_msg.c \
	px_check_command.c \
	px_split_res.c \
	px_split_res_utils.c \
	px_input_file_handler.c \
	px_output_file_handler.c \
	px_write_to_file.c \
	px_fork.c

all:$(NAME)

$(NAME): $(MAIN) $(SRC) $(GNL)
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
