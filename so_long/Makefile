# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:51:17 by lgenevey          #+#    #+#              #
#    Updated: 2022/04/01 16:26:49 by lgenevey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

# Library Name #
NAME = so_long

# Variables #
SRC =

# Compiling Variables #
CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror
INCLUDE	=	-Imlx -Lmlx mlx/libmlx.a -framework OpenGL -framework AppKit
RM		=	rm -f

# Colors #
# Exemple : echo -e "blablabla $(OK_COLOR)ici la couleur $(NO_COLOR)"
COM_COLOR	= \033[0;34m
OBJ_COLOR	= \033[0;36m
OK_COLOR	= \033[0;32m
ERROR_COLOR	= \033[0;31m
WARN_COLOR	= \033[0;33m
NO_COLOR	= \033[m

all: $(NAME)

clean:
	@rm -rf *.c
	@echo "$(OK_COLOR)[SUCCESS] '.o' DELETED$(NO_COLOR)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(OK_COLOR)[SUCCESS] '.a' DELETED$(NO_COLOR)"

re: fclean all
	@echo "$(OK_COLOR)[SUCCESS] clean and make$(NO_COLOR)"
