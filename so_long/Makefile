# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:51:17 by lgenevey          #+#    #+#              #
#    Updated: 2022/03/28 13:03:50 by lgenevey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library Name #
NAME = so_long.a

# Variables #
SRC =

# Compiling Variables #
CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror
INCLUDE	=	-Imlx -Lmlx mlx/libmlx.a -framework OpenGL -framework AppKit
RM		=	rm -f
OBJ		=	*.o

# Colors #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all: $(NAME)

clean:

fclean:

re: fclean all

.PHONY: all clean fclean re