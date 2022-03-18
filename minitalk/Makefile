# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 15:59:08 by lgenevey          #+#    #+#              #
#    Updated: 2022/03/18 17:11:44 by lgenevey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	# Library Name #
NAME =
CLIENT	=	client
SERVER	=	server

	# ft_printf Variables #
FT_PRINTF		=	./FT_PRINTF/FT_PRINTF.a
FT_PRINTF_DIR	=	./FT_PRINTF

	# Mandatory Variables #
CLIENT_SRC	=	./src/client.c
SERVER_SRC	=	./src/server.c


INC		=	-I. -I$(FT_PRINTF_DIR)

	# Compiling Variables #
CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -f

	# Colors #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]


all: $(SERVER) $(CLIENT)
bonus: all

$(NAME): all

$(SERVER): $(FT_PRINTF)
	@ $(CC) $(CFLAG) $(SERVER_SRC) $(FT_PRINTF) $(INC) -o $(SERVER)
	@printf "$(_SUCCESS) server ready.\n"

$(CLIENT): $(FT_PRINTF)
	@ $(CC) $(CFLAG) $(CLIENT_SRC) $(FT_PRINTF) $(INC) -o $(CLIENT)
	@printf "$(_SUCCESS) client ready.\n"


$(FT_PRINTF):
	@ $(MAKE) -C ./FT_PRINTF

clean:
	@ $(RM) $(CLIENT) $(SERVER)
	@printf "$(_INFO) client removed.\n"
	@printf "$(_INFO) server removed.\n"

fclean:
	@ $(MAKE) fclean -C $(FT_PRINTF_DIR)
	@ $(RM) $(CLIENT) $(SERVER)
	@printf "$(_INFO) client removed.\n"
	@printf "$(_INFO) server removed.\n"

re: fclean all

.PHONY: all clean fclean re mandatory m bonus b
