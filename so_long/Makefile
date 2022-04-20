# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:51:17 by lgenevey          #+#    #+#              #
#    Updated: 2022/04/20 20:07:15 by lgenevey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
NAME_BONUS	=	so_long_bonus

SRCS			=	sources/so_long.c \
				sources/get_next_line_utils.c \
				sources/get_next_line.c \
				sources/map_check.c \
				sources/map_read.c \
				sources/init_structures.c \
				sources/window.c

LIBFT_DIR		=	libraries/libft
LIBFT			=	libraries/libft/libft.a
FT_PRINTF_DIR	=	libraries/libft/ft_printf
FT_PRINTF		=	libraries/libft/ft_printf/libftprintf.a
MINILIBX_DIR	=	libraries/minilibx
MINILIBX		=	libraries/minilibx/libmlx.a

OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
RM		=	rm -f

DEBUG	=	-fsanitize=address -g3
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-L $(LIBFT_DIR) -lft -L $(MINILIBX_DIR) -lmlx -L $(FT_PRINTF_DIR) -lftprintf -framework OpenGL -framework AppKit
RM		=	rm -f

BLUE	= \033[0;34m
VIOLET	= \033[0;36m
GREEN	= \033[0;32m
RED		= \033[0;31m
YELLOW	= \033[0;33m
NONE	= \033[0m

help: ## Print help on Makefile
	@grep '^[^.#]\+:\s\+.*#' Makefile | \
	sed "s/\(.\+\):\s*\(.*\) #\s*\(.*\)/`printf "\033[93m"`\1`printf "\033[0m"`	\3 [\2]/" | \
	expand -t15

all:	$(NAME)	## Compile every mandatory files

$(NAME)	:	$(OBJS)
	@echo "$(BLUE)     - Making minilibx... $(NONE)"
	@$(MAKE) -C $(MINILIBX_DIR)
	@echo "$(BLUE)     - Making libft... $(NONE)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(BLUE)     - Making ft_printf... $(NONE)"
	@$(MAKE) -C $(FT_PRINTF_DIR)
	@echo "$(BLUE)     - Making so_long... $(NONE)"
	@$(CC) $(OBJS) $(CFLAGS) -I $(MINILIBX_DIR) -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR) $(INCLUDE) -o $(NAME)
	@printf "$(GREEN) so_long ready.\n$(NONE)"

bonus:	$(NAME_BONUS)	## Compile every bonus files

norm:	## Apply Norminette check
	@echo "$(VIOLET)[NORM - START]"
	@norminette sources/*.*
	@echo "[NORM - END]$(NONE)"

clean: ## Clean generated files
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@printf "$(GREEN) OBJS removed.\n$(NONE)"

fclean:	clean	## Clean generated files plus the library .o and .a
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@printf "$(GREEN) libft.a removed.\n$(NONE)"
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@printf "$(GREEN) libmlx.a removed.\n$(NONE)"
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@printf "$(GREEN) libftprintf.a removed.\n$(NONE)"
	@printf "$(GREEN) so_long removed.\n$(NONE)"

re: fclean all	# fclean then all

.PHONY:	all clean fclean re norm bonus help