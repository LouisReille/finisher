# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdescour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 21:52:45 by cdescour          #+#    #+#              #
#    Updated: 2023/03/21 20:46:25 by lreille          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary
NAME = miniRT
LIBFT = libft

# Path
SRC_PATH = ./src/
OBJ_PATH = ./objets/
IMG_PATH = ./images/
CPPFLAGS = -I./includes/

# Name
SRC_NAME =	check_obj.c				\
			error.c					\
			free.c					\
			ft_check_data_1.c		\
			ft_data_utils1.c		\
			ft_data_utils2.c		\
			ft_elem_cap_check.c		\
			ft_elem_cap_inputbis.c	\
			ft_elem_min_check.c		\
			ft_elem_min_inputbis.c	\
					ft_utils1.c				\
			ft_utils2.c	\
			ft_utils3.c	\
			vector_utils1.c	\
			vector_utils2.c	\
			get_next_line.c			\
			get_next_line_utils.c	\
			main.c					\
			ft_elem_cap_input.c	\
			ft_elem_min_input.c\
			parse_file.c			\
			amb.c					\
			cam.c					\
			rotation.c	\
			color.c	\
			ft_splitbis.c	\
			ft_min_vec.c	\
			ft_mlx.c \
			spot.c

OBJ_NAME = $(SRC_NAME:.c=.o)
IMG_NAME =	render.xpm

# Files
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
IMG = $(addprefix $(IMG_PATH), $(IMG_NAME))

# Flags
LDFLAGS = -L./libft/
LFT = -lft
CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[34mCreation of $(LIBFT) ...\033[0m"
	@make -C./libft/
	@echo "\033[32m$(LIBFT) created\033[0m"
	@echo "\033[34mCreation of $(NAME) ...\033[0m"
	@$(CC) $(LDFLAGS) $(LFT) $(OBJ) -o $@ $(MLX)
	@echo "\033[32m$(NAME) created\n\033[0m"
	@echo "\033[31mEND: everything is complete.\033[0m"


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mkdir $(IMG_PATH) 2> /dev/null || true
	@$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	@make clean -C ./libft/
	@echo "\033[33mRemoval of .o files of $(NAME) ...\033[0m"
	@rm -f $(OBJ)
	@rm -f $(IMG)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@rmdir $(IMG_PATH) 2> /dev/null || true
	@echo "\033[31mFiles .o deleted\n\033[0m"
	
fclean: clean
	@make fclean -C ./libft/
	@echo "\033[33mRemoval of $(NAME)...\033[0m"
	@rm -f $(NAME)
	@echo "\033[31mBinary $(NAME) deleted\n\033[0m"

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY: all, clean, fclean, re
