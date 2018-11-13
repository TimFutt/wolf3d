# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tifuret <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/30 14:09:18 by tifuret           #+#    #+#              #
#    Updated: 2018/11/01 15:21:38 by chaydont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=wolf3d
LIBFT=libft/libft.a

SRC_NAME=raycasting.c\
		 draw.c\
		 main.c\
		 parser.c \
		 difficulty_hook.c \
		 menu.c \
		 menu_hook.c \
		 put_strings.c \
		 resolutions_hook.c \
		 settings_hook.c \
		 hook.c \
		 utils.c \
		 textures.c


SRC=$(addprefix srcs/, $(SRC_NAME))
OBJ=$(patsubst srcs/%.c, obj/%.o, $(SRC))

OBJ_DIR=obj

CC=gcc
INC=-Iincludes -Ilibft/includes
MLX=-lmlx -framework OpenGL -framework AppKit
CFLAGS= -Wall -Wextra -Werror -g $(INC)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@echo "Compile the game"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

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
