NAME = fractol

CC = gcc

SRC_DIR = ./src/
SRC_LIST = main.c ft_paint_fractal.c \
	ft_drawing_line.c ft_fractal_rectangle.c \
	ft_fractal_julia.c ft_fractal_mandelbrota.c ft_fractal_symmetry.c\
	ft_pixel_color.c \
	ft_operation_key.c ft_operation_mouse.c \
	ft_standard_methods.c

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJECTS_DIR = ./objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))

HEADER_DIR = ./includes/
HEADER_LIST = fractol.h structure.h error.h menu.h key_linux.h key_macos.h
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_LIST))

INCLUDES = -I $(HEADER_DIR) -I $(LIBFT_DIR)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBRARIES = $(LIBFT) $(MLX)

ifeq ($(OS), Linux)
	MLX_DIR = ./minilibx/
	MLX = -L ./minilibx/ -lmlx -lXext -lX11 -lm -lpthread -lz
else
	MLX_DIR = ./minilibx_macos/
	MLX = -L ./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit
endif

FLAGS = -Wall -Wextra -Werror -std=c99 -O3

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re FAKE

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIR) $(OBJECTS)
		@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(LIBRARIES)
		@echo "✅\n\033[34m$(NAME):\033[32m was created\033[0m"

$(OBJECTS_DIR):
		@mkdir -p $(OBJECTS_DIR)
		@echo "✅\033[34m$(NAME):\033[32m $(OBJECTS_DIR)directory was created\033[0m"

$(OBJECTS_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
		@$(CC) $(FLAGS) -c $(INCLUDES) -o $@ $<
		@echo "✅\c"

$(LIBFT): FAKE
		@$(MAKE) -C $(LIBFT_DIR)
		@$(MAKE) -C $(MLX_DIR)

test: all
		./$(NAME) Julia

clean:
		@rm -rf $(OBJECTS_DIR)
		@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		@/bin/rm -f $(NAME)
		@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

# minilibx_macos/libmlx.a -framework OpenGL -framework AppKit
# -L minilibx -lmlx -framework OpenGL -framework AppKit
# INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)
# $(CC) $(FLAGS) -c -I$(HEADERS_DIRECTORY) -o $@ $<