# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:51:17 by lgenevey          #+#    #+#              #
#    Updated: 2022/04/01 19:24:57 by lgenevey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
NAME_BONUS		=	so_long_bonus

LIBFT_DIR	=	libraries/libft/
LIBFT		=	$(LIBFT_DIR)libft.a

FT_PRINTF_DIR	=	libraries/libft/ft_printf/
FT_PRINTF		=	$(FT_PRINTF_DIR)libftprintf.a

MINILIBX_DIR	=	libraries/minilibx/
MINILIBX		=	$(MINILIBX_DIR)libmlx.a

SRC	=	sources/*.c
OBJ	=	$(SRC:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-Iminilibx -Lminilibx minilibx/libmlx.a -framework OpenGL -framework AppKit
RM		=	rm -f

COM_COLOR	= \033[0;34m
OBJ_COLOR	= \033[0;36m
OK_COLOR	= \033[0;32m
ERROR_COLOR	= \033[0;31m
WARN_COLOR	= \033[0;33m
NO_COLOR	= \033[m

help: # Print help on Makefile
	@grep '^[^.#]\+:\s\+.*#' Makefile | \
	sed "s/\(.\+\):\s*\(.*\) #\s*\(.*\)/`printf "\033[93m"`\1`printf "\033[0m"`	\3 [\2]/" | \
	expand -t20

all:	$(NAME) # Compile every mandatory files

bonus:	$(NAME_BONUS) # Compile every bonus files

$(NAME): $(LIBFT) $(OBJ)
	@echo "$(COM_COLOR)     - Compiling minilibx and libft libraries... $(NO_COLOR)"
	@$(MAKE) -C $(MINILIBX_DIR)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(OBJ): $(SRC)
	@echo "$(COM_COLOR)     - Making object files... $(NO_COLOR)"
	@gcc $(CFLAGS) -c $(SRC)

norm: # Apply Norminette check
	@echo $(OBJ_COLOR) "[NORM - START]"
	@norminette $(SRC) sources/*.h
	@echo $(NO_COLOR) "[NORM - END]"

clean: # Clean generated files
	@echo "$(OK_COLOR)[SUCCESS] '.o' DELETED$(NO_COLOR)"
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MINILIBX_DIR) clean
	$(RM) $(OBJ_DIR)

fclean:	clean # Clean generated files plus the library .o and .a
	@echo "$(OK_COLOR)[SUCCESS] '.a' DELETED$(NO_COLOR)"
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all # fclean then all
	@echo "$(OK_COLOR)[SUCCESS] clean and make$(NO_COLOR)"

.PHONY:	all clean fclean re norm bonus help