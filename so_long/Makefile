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

GNL_DIR		=	libraries/gnl/

SRC	=	sources/*.c
OBJ	=	$(SRC:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-Imlx -Lmlx mlx/libmlx.a -framework OpenGL -framework AppKit
RM		=	rm -rf

COM_COLOR	= \033[0;34m
OBJ_COLOR	= \033[0;36m
OK_COLOR	= \033[0;32m
ERROR_COLOR	= \033[0;31m
WARN_COLOR	= \033[0;33m
NO_COLOR	= \033[m

all:	$(NAME)

bonus:	$(NAME_BONUS)

$(NAME): $(OBJ)
	@echo $(COM_COLOR) "     - Making libft..." $(NO_COLOR)
	@make -C $(LIBF_DIR)
	@echo $(COM_COLOR) "     - Compiling $(NAME)..." $(NO_COLOR)
	@gcc $(CFLAGS) $(OBJ) $(LIBFT) $(INCLUDE) -o $(NAME)
	@echo $(OK_COLOR)"- Compiled -"$(NO_COLOR)

$(OBJ): $(SRC)
	@echo $(COM_COLOR) "     - Making object files..." $(NO_COLOR)
	@gcc $(CFLAGS) -c $(SRC)

norm:
	@echo $(OBJ_COLOR) "[NORM - START]"
	@norminette $(SRC) sources/*.h
	@echo $(NO_COLOR) "[NORM - END]"

clean:
	@echo "$(OK_COLOR)[SUCCESS] '.o' DELETED$(NO_COLOR)"
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MINILIBX_PATH) clean
	$(RM) $(OBJ_DIR)

fclean:	clean
	@echo "$(OK_COLOR)[SUCCESS] '.a' DELETED$(NO_COLOR)"
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all
	@echo "$(OK_COLOR)[SUCCESS] clean and make$(NO_COLOR)"

.PHONY:	all clean fclean re norm bonus