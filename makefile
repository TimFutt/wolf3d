NAME = wolf3d

SRC = srcs/main.c \
			srcs/menu.c \
			srcs/menu_hook.c \
			srcs/init.c

OBJ = objs/main.o \
	  objs/menu.o \
	  objs/menu_hook.o \
	  objs/init.o

LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) :
		@make -C ./libft/
		@gcc -c $(FLAGS) $(SRC)
		@echo "\033[31m[COMPILATION]\033[0m"
		@mkdir objs
		@mv *.o objs
		@gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME) $(MLX)
		@echo "\033[36m[WOLF3D CREATED]\033[0m"

clean :
	@rm -rf $(OBJ)
	@make clean -C ./libft/
	@echo "\033[32m[CLEANING LIBFT OBJECTS]\033[0m"
	@rm -rf objs
	@rm -rf *.o
	@echo "\033[32m[CLEANING WOLF3D OBJECTS]\033[0m"

fclean : clean
	@make fclean -C ./libft/
	@rm -rf $(NAME)
	@@echo "\033[32m[CLEANING WOLF3D]\033[0m"

re : fclean all
