NAME=wolf3d
LIBFT=libft.a
LIBFT_PATH=./libft

SRC_NAME=

SRC=$(addprefix srcs/, $(SRC_NAME))
OBJ=$(patsubst srcs/%.c, obj/%.o, $(SRC))

OBJ_DIR=obj

CC=gcc
INC=-Iincludes -Ilibft/includes
MLX=-lmlx -framework OpenGL -framework AppKit
CFLAGS=-Wall -Wextra -Werror -g $(INC) -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@echo "Compile the game"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_PATH)/$(LIBFT) $(MLX)

obj/%.o: srcs/%.c
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C libft clean
	@rm -rf obj

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all
