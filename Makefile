CC = cc
FLAGS = -Wall -Wextra -Werror -g3
NAME = cub3D
SRCS = srcs/timer/mapping_num.c srcs/timer/timer.c srcs/minimap/draw_map.c srcs/minimap/draw_minimap.c srcs/minimap/raycast.c srcs/parser/parse_map.c srcs/parser/parse_error.c srcs/parser/parse_line.c srcs/parser/parse_base.c srcs/utils/colors.c srcs/utils/pixel_put.c srcs/utils/rect.c srcs/utils/camera.c srcs/utils/key_hook.c srcs/utils/move.c srcs/utils/ray_dda.c srcs/utils/render.c srcs/utils/time.c srcs/init.c srcs/destroy.c srcs/main.c
OBJ = $(SRCS:.c=.o)
LIB_PATH = -Lmlx_linux -Llibft -L/usr/lib
LIB_NAME = -lmlx_Linux -lft -lXext -lX11 -lm -lz
INCLUDE_PATH = -I/usr/include -Imlx_linux -Ilibft/includes -Iincludes

VALID = \033[1;32m
NOTVALID = \033[1;31m
LOADING = \033[1;33m
INFOS = \033[1;36m
RESET = \033[0m

MLX_LINK = https://cdn.intra.42.fr/document/document/34997/minilibx-linux.tgz

all: MLX libft/libft.a $(NAME)

DL_MLX:
	@if [ ! -d "mlx_linux" ]; then \
        printf "$(VALID)⇩ Downloading and extracting minilibx...\n$(LOADING)"; \
        wget $(MLX_LINK)  >> /dev/null; \
        tar -xf minilibx-linux.tgz; \
        mv minilibx-linux mlx_linux; \
		printf "$(RESET)";\
    else \
        echo "✅ $(VALID)mlx-linux already downloaded.$(RESET)"; \
    fi

MLX: DL_MLX
	@printf "$(VALID)⇩ Make MLX\n$(RESET)";
	@$(MAKE) -C mlx_linux > /dev/null 2>&1

libft/libft.a:
	@printf "$(VALID)⇩ Make Libft\n$(RESET)";
	@$(MAKE) -C libft > /dev/null 2>&1

%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDE_PATH) -O3 -c $< -o $@
$(NAME): $(OBJ)
	@echo "$(INFOS)Flags:$(FLAGS)\ninclude:$(INCLUDE_PATH)\nObj:$(OBJ)\nlib:$(LIB_NAME)$(RESET)\n";
	$(CC) $(FLAGS) $(OBJ) $(LIB_PATH) $(LIB_NAME) $(INCLUDE_PATH) -o $(NAME)

clean_mlx:
	@printf "$(NOTVALID)Cleanning MLX \n$(RESET)";
	@$(MAKE) -C libft clean > /dev/null 2>&1
	@rm -rf minilibx-linux.tgz

clean: clean_mlx
	@printf "$(NOTVALID)Cleanning LIBFT \n$(RESET)";
	@$(MAKE) -C libft clean > /dev/null 2>&1
	@printf "$(NOTVALID)Remove *.o \n$(RESET)";
	@rm -rf $(OBJ)

fclean: clean
	@printf "$(NOTVALID)Remove CUB3D && libft.a\n$(RESET)";
	@rm -rf $(NAME) libft/libft.a

aclean: fclean
	@printf "$(NOTVALID)Remove mlx_linux repertory\n$(RESET)";
	@rm -rf mlx_linux

re : fclean all

rr: aclean all

listC:
	@LIST=$$(find -wholename "./srcs/*.c" | cut -c 3- | tr '\n' ' '); \
	printf "🗅 $(INFOS)copy all C sources files into clipboard :\n$(RESET)$$LIST\n"; \
	echo $$LIST | xclip -selection clipboard

