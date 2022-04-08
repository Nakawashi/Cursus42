# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:51:17 by lgenevey          #+#    #+#              #
#    Updated: 2022/04/08 18:58:23 by lgenevey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
NAME_BONUS		=	so_long_bonus

LIBFT			=	libraries/libft/libft.a

FT_PRINTF		=	libraries/libft/ft_printf/libftprintf.a

MINILIBX		=	libraries/minilibx/libmlx.a

SOURCES	=	sources/*.c
HEADERS	=	sources/*.h
OBJ		=	$(SOURCES:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-framework OpenGL -framework AppKit
AR		=	ar rc
RM		=	rm -f

COM_COLOR	= \033[0;34m
OBJ_COLOR	= \033[0;36m
OK_COLOR	= \033[0;32m
ERROR_COLOR	= \033[0;31m
WARN_COLOR	= \033[0;33m
NO_COLOR	= \033[m

help: ## Print help on Makefile
	@grep '^[^.#]\+:\s\+.*#' Makefile | \
	sed "s/\(.\+\):\s*\(.*\) #\s*\(.*\)/`printf "\033[93m"`\1`printf "\033[0m"`	\3 [\2]/" | \
	expand -t20

all:	$(NAME)	## Compile every mandatory files

bonus:	$(NAME_BONUS)	## Compile every bonus files

$(NAME): $(OBJ)
	$(CC) $(SOURCES) -I$(HEADERS) $(LIBFT) $(FT_PRINTF) $(MINILIBX) $(INCLUDE) -o $(NAME)

norm:	## Apply Norminette check
	@echo "$(OBJ_COLOR)[NORM - START]"
	@norminette sources/*.*
	@echo "[NORM - END]$(NO_COLOR)"

clean:	## Clean generated files


fclean:	clean	## Clean generated files plus the library .o and .a


re: fclean all	# fclean then all


.PHONY:	all clean fclean re norm bonus help