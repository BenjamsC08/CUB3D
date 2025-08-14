CC = cc
FLAGS = -Wall -Wextra -Werror -g3
NAME = CUB3D
SRCS = srcs/main.c srcs/parser/parsing_1.c
OBJ = $(SRCS:.c=.o)
LIB_PATH = -Lmlx_linux -Llibft -L/usr/lib
LIB_NAME = -lmlx_Linux -lft -lXext -lX11 -lm -lz
INCLUDE_PATH = -I/usr/include -Imlx_linux -Ilibft/includes -Iincludes

all: MLX libft/libft.a $(NAME)

MLX:
	make -C mlx_linux > /dev/null 2>&1

libft/libft.a:
	$(MAKE) -C libft > /dev/null 2>&1

%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDE_PATH) -O3 -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIB_PATH) $(LIB_NAME) $(INCLUDE_PATH) -o $(NAME)
clean:
	rm -rf $(OBJ)
	$(MAKE) -C libft clean > /dev/null 2>&1
clean_mlx:
	rm -rf minilibx-linux.tgz
	rm -rf mlx_linux
fclean: clean
	rm -rf $(NAME) libft/libft.a
re : fclean all

listC:
	@find -wholename "./srcs/*.c" | cut -c 3- | tr '\n' ' '
