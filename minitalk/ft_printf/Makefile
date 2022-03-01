# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 13:38:53 by lgenevey          #+#    #+#              #
#    Updated: 2022/03/01 15:11:39 by lgenevey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
SRCS =	ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_positive_putnbr.c \
		ft_putbase.c \
		ft_putpointer.c \
		ft_norminette.c

OBJS = ${SRCS:.c=.o}
NAME = ft_printf.a
AR = ar rc
RM = rm -f
LIBFT_PATH = $(PARENT_DIR)
all: ${NAME}
${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}
clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re