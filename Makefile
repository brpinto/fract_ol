# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 14:03:54 by brpinto           #+#    #+#              #
#    Updated: 2019/06/03 17:18:22 by brpinto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = clang
FLAGS = -Wall -Wextra -Werror

SRC_PATH = ./srcs/
OBJ_PATH = ./srcs/obj/
LIB_PATH = ./libft/
INC_PATH = ./includes/

MLX_HEADER = ./minilibx_macos/include/
MLX_LIB = ./minilibx_macos/

SRC_FILES = main.c			\
			error.c			\
			init.c			\
			init_fctl.c		\
			fractals.c		\
			display.c		\
			color.c			\
			threads.c		\
			key_hook.c		\
			mouse_press.c  	\
			mouse_move.c	\
			close.c			\
			fract_calc.c

LIB_FILES = libft.a
LIB = $(addprefix $(LIB_PATH), $(LIB_FILES))

OBJ_FILES = $(SRC_FILES:.c=.o)
	OBJ_EXEC = $(addprefix $(OBJ_PATH), $(OBJ_FILES))

all: $(NAME)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC_PATH) -I $(LIB_PATH)includes -I $(MLX_HEADER)

$(LIB):
	@make -C $(LIB_PATH)

$(MLX):
	@make -C $(MLX_LIB)

$(NAME): $(MLX) $(LIB) $(OBJ_PATH) $(OBJ_EXEC)
	@$(CC) $(FLAGS) $(OBJ_EXEC) $(LIB) -o $(NAME) -I $(INC_PATH)  -L $(MLX_LIB) -lmlx -framework OpenGL -framework AppKit

	@echo "\033[1;32m$(notdir $(NAME))\033[1;0m\033[32m created.\033[0m"

clean:
	@/bin/rm -rf $(OBJ_PATH)
	@make clean -C $(LIB_PATH)
	@echo "\033[31mObjects files of \033[1;31m$(notdir $(NAME))\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@make fclean -C $(LIB_PATH)
	@/bin/rm -rf $(NAME)
	@echo "\033[1;31m$(notdir $(NAME))\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
