# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:51:17 by lgenevey          #+#    #+#              #
#    Updated: 2022/04/01 18:32:24 by lgenevey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINILIBX_PATH = mlx

# Library Name #
NAME = so_long

# File sources #
SRC = *.c
OBJ = $(SRC:.c=.o)

CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror
INCLUDE	=	-Imlx -Lmlx mlx/libmlx.a -framework OpenGL -framework AppKit

COM_COLOR	= \033[0;34m
OBJ_COLOR	= \033[0;36m
OK_COLOR	= \033[0;32m
ERROR_COLOR	= \033[0;31m
WARN_COLOR	= \033[0;33m
NO_COLOR	= \033[m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(COM_COLOR)[OK] Generating $(NAME)...$(NO_COLOR)"
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -rf *.c
	@echo "$(OK_COLOR)[SUCCESS] '.o' DELETED$(NO_COLOR)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(OK_COLOR)[SUCCESS] '.a' DELETED$(NO_COLOR)"

re: fclean all
	@echo "$(OK_COLOR)[SUCCESS] clean and make$(NO_COLOR)"

.PHONY: all clean fclean re