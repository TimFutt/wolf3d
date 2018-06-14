NAME = Wolf3d

SRC = srcs/main.c \
			srcs/menu.c \
			srcs/menu_hook.c \
			srcs/settings_hook.c \
			srcs/diffculty_hook.c \
			srcs/graphics_hook.c \
			srcs/put_strings.c \
			srcs/resolutions_hook.c \

OBJ = objs/main.o \
	  objs/menu.o \
	  objs/menu_hook.o \
	  objs/settings_hook.o \
	  objs/diffculty_hook.o \
	  objs/graphics_hook.o \
	  objs/put_strings.o \
	  objs/resolutions_hook.o

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
	@rm -rf *.o
	@rm -rf $(OBJ)
	@make clean -C ./libft/
	@echo "\033[32m[CLEANING LIBFT OBJECTS]\033[0m"
	@rm -rf objs
	@echo "\033[32m[CLEANING WOLF3D OBJECTS]\033[0m"

fclean : clean
	@make fclean -C ./libft/
	@rm -rf $(NAME)
	@@echo "\033[32m[CLEANING WOLF3D]\033[0m"

re : fclean all
