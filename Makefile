NAME = fractol

CC = gcc

SRC_DIR = ./src/
SRC_LIST = main.c ft_drawing_line.c ft_pixel_color.c ft_operation_key.c \
			ft_operation_mouse.c ft_multi_thread.c ft_fractal_julia.c \
			ft_fractal_rectangle.c ft_fractal_mandelbrota.c

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJECTS_DIR = ./objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))

HEADER_DIR = ./includes/
HEADER_LIST = fractol.h
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_LIST))

LIBFT = libft.a
LIBFT_DIR = ../libft/

MLX = -L minilibx -lmlx -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror -std=c99 -O3

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIR) $(OBJECTS)
		@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) -I $(HEADER_DIR) \
		-L $(LIBFT_DIR) -lft $(MLX)
		@echo "\033[32m$(NAME): was created\033[0m"

$(OBJECTS_DIR):
		@mkdir -p $(OBJECTS_DIR)
		@echo "\033[32m$(NAME): $(OBJECTS_DIR)directory was created\033[0m"

$(OBJECTS_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
		@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

$(LIBFT):
		@$(MAKE) -C $(LIBFT_DIR)

clean:
		@rm -rf $(OBJECTS_DIR)
		@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		@/bin/rm -f $(NAME)
		@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
# minilibx_macos/libmlx.a -framework OpenGL -framework AppKit
# -L minilibx -lmlx -framework OpenGL -framework AppKit