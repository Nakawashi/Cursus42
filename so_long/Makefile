# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:51:17 by lgenevey          #+#    #+#              #
#    Updated: 2022/05/17 17:06:46 by lgenevey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
NAME_BONUS	=	so_long_bonus

SRCS			=	sources/so_long.c \
					sources/get_next_line_utils.c \
					sources/get_next_line.c \
					sources/map_check.c \
					sources/map_check_utils.c \
					sources/map_read.c \
					sources/game_init.c \
					sources/map_init.c \
					sources/game_hooks.c \
					sources/player_moves.c \
					sources/handle_items.c \
					sources/clean_stuff.c

LIBFT_DIR		=	libraries/libft
LIBFT			=	libraries/libft/libft.a
FT_PRINTF_DIR	=	libraries/libft/ft_printf
FT_PRINTF		=	libraries/libft/ft_printf/libftprintf.a
MINILIBX_DIR	=	libraries/minilibx
MINILIBX		=	libraries/minilibx/libmlx.a

OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
RM		=	rm -f

#DEBUG	=	-fsanitize=address -g3
DEBUG	=	-g3
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-L $(LIBFT_DIR) -lft -L $(MINILIBX_DIR) -lmlx -L $(FT_PRINTF_DIR) -lftprintf -framework OpenGL -framework AppKit
RM		=	rm -f

BLUE	= \033[0;34m
VIOLET	= \033[0;36m
GREEN	= \033[0;32m
RED		= \033[0;31m
YELLOW	= \033[0;33m
NONE	= \033[0m

all:	$(NAME)

$(NAME)	:	$(OBJS)
	@echo "$(BLUE)Making minilibx... $(NONE)"
	@$(MAKE) -C $(MINILIBX_DIR)
	@echo "$(BLUE)Making libft... $(NONE)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(BLUE)Making ft_printf... $(NONE)"
	@$(MAKE) -C $(FT_PRINTF_DIR)
	@echo "$(BLUE)Making so_long... $(NONE)"
	@$(CC) $(OBJS) $(CFLAGS) $(DEBUG) -I $(MINILIBX_DIR) -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR) $(INCLUDE) -o $(NAME)
	@printf "$(GREEN) so_long ready.\n$(NONE)"

bonus:	$(NAME_BONUS)

norm:
	@echo "$(VIOLET)[NORM - START]$(NONE)"
	@norminette sources/*.*
	@echo "$(VIOLET)[NORM - END]$(NONE)"

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@printf "$(GREEN) OBJS removed.\n$(NONE)"

fclean:	clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@printf "$(GREEN) libft.a removed.\n$(NONE)"
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@printf "$(GREEN) libmlx.a removed.\n$(NONE)"
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@printf "$(GREEN) libftprintf.a removed.\n$(NONE)"
	@printf "$(GREEN) so_long removed.\n$(NONE)"

re: fclean all

.PHONY:	all clean fclean re norm help
