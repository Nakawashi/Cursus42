# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:51:17 by lgenevey          #+#    #+#              #
#    Updated: 2022/09/13 00:43:56 by nakawashi        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRCS	=	sources/main.c \
			sources/mini_libft.c \
			sources/utils.c \
			sources/init.c \
			sources/start_simulation.c \
			sources/routine.c \

OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
RM		=	rm -f

DEBUG	=	-fsanitize=thread -g
#DEBUG	=	-g3
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-L

BLUE	= \033[0;34m
VIOLET	= \033[0;36m
GREEN	= \033[0;32m
RED		= \033[0;31m
YELLOW	= \033[0;33m
NONE	= \033[0m

all:	$(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(DEBUG) -I $(INCLUDE) -o $(NAME)
	@printf "$(GREEN) $(NAME) ready.\n$(NONE)"

norm:
	@echo "$(VIOLET)[NORM - START]$(NONE)"
	@norminette sources/*.*
	@echo "$(VIOLET)[NORM - END]$(NONE)"

clean:
	@$(RM) $(OBJS)
	@printf "$(GREEN) object files removed.\n$(NONE)"

fclean:	clean
	@$(RM) $(NAME)
	@printf "$(GREEN) $(NAME) removed.\n$(NONE)"

re: fclean all

.PHONY:	all clean fclean re norm
