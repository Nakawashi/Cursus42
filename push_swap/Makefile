# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:51:17 by lgenevey          #+#    #+#              #
#    Updated: 2022/05/30 16:14:29 by lgenevey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	sources/push_swap.c \
			sources/init_structures.c \
			sources/parse_argv.c

LIBFT_DIR		=	libraries/libft
LIBFT			=	libraries/libft/libft.a
FT_PRINTF_DIR	=	libraries/libft/ft_printf
FT_PRINTF		=	libraries/libft/ft_printf/libftprintf.a

OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
RM		=	rm -f

DEBUG	=	-fsanitize=address -g3
#DEBUG	=	-g3
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-L $(LIBFT_DIR) -lft -L $(FT_PRINTF_DIR) -lftprintf
RM		=	rm -f

BLUE	= \033[0;34m
VIOLET	= \033[0;36m
GREEN	= \033[0;32m
RED		= \033[0;31m
YELLOW	= \033[0;33m
NONE	= \033[0m

all:	$(NAME)

$(NAME)	:	$(OBJS)
	@echo "$(BLUE)Making libft... $(NONE)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(BLUE)Making ft_printf... $(NONE)"
	@$(MAKE) -C $(FT_PRINTF_DIR)
	@echo "$(BLUE)Making $(NAME)... $(NONE)"
	@$(CC) $(OBJS) $(CFLAGS) $(DEBUG) -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR) $(INCLUDE) -o $(NAME)
	@printf "$(GREEN) $(NAME) ready.\n$(NONE)"

norm:
	@echo "$(VIOLET)[NORM - START]$(NONE)"
	@norminette sources/*.*
	@echo "$(VIOLET)[NORM - END]$(NONE)"

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@printf "$(GREEN) OBJS removed.\n$(NONE)"

fclean:	clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@printf "$(GREEN) libft.a removed.\n$(NONE)"
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@printf "$(GREEN) libftprintf.a removed.\n$(NONE)"
	@printf "$(GREEN) $(NAME) removed.\n$(NONE)"

re: fclean all

.PHONY:	all clean fclean re norm
