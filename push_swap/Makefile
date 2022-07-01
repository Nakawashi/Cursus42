# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:51:17 by lgenevey          #+#    #+#              #
#    Updated: 2022/07/01 23:48:35 by nakawashi        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	sources/main.c \
			sources/parse_argv.c \
			sources/utils.c \
			sources/utils_stack.c \
			sources/free_utils.c \
			sources/push_swap.c \
			sources/small_sort.c \
			sources/big_sort.c \
			sources/big_sort_utils.c \
			sources/operations/push.c \
			sources/operations/swap.c \
			sources/operations/rotate.c \
			sources/operations/reverse_rotate.c

LIBFT_DIR		=	libraries/libft
LIBFT			=	libraries/libft/libft.a

OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
RM		=	rm -f

DEBUG	=	-fsanitize=address -g
#DEBUG	=	-g3
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-L $(LIBFT_DIR) -lft
RM		=	rm -f

BLUE	= \033[0;34m
VIOLET	= \033[0;36m
GREEN	= \033[0;32m
RED		= \033[0;31m
YELLOW	= \033[0;33m
NONE	= \033[0m

all:	$(NAME)

$(NAME)	: $(OBJS)
	@echo "$(BLUE)Making libft and bonuses... $(NONE)"
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(LIBFT_DIR) bonus
	@$(CC) $(OBJS) $(CFLAGS) $(DEBUG) -I $(LIBFT_DIR) $(INCLUDE) -o $(NAME)
	@printf "$(GREEN) $(NAME) ready.\n$(NONE)"

norm:
	@echo "$(VIOLET)[NORM - START]$(NONE)"
	@norminette sources/*.*/*.*
	@echo "$(VIOLET)[NORM - END]$(NONE)"

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@printf "$(GREEN) OBJS removed.\n$(NONE)"

fclean:	clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@printf "$(GREEN) libft.a removed.\n$(NONE)"
	@printf "$(GREEN) $(NAME) removed.\n$(NONE)"

re: fclean all

.PHONY:	all clean fclean re norm
