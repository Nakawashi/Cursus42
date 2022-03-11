# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 15:59:08 by lgenevey          #+#    #+#              #
#    Updated: 2022/03/11 16:56:00 by lgenevey         ###   ########.fr        #
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
INC		=	-I. -I$(FT_PRINTF_DIR) -I$(FT_PRINTF_DIR)/stack \
			-I$(FT_PRINTF_DIR)/get_next_line

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

	# Debugger https://github.com/mlanca-c/Minitalk/blob/main/Makefile #
ifeq ($(DEBUG), 1)
	D_FLAG	=	-g
endif

	# Fsanitize #
ifeq ($(SANITIZE), 1)
	D_FLAG	=	-fsanitize=leak -g
endif

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER): $(FT_PRINTF)
	@ $(CC) $(D_FLAG) $(CFLAG) $(SERVER_SRC) $(FT_PRINTF) $(INC) -o $(SERVER)
	@printf "$(_SUCCESS) server ready.\n"

$(CLIENT): $(FT_PRINTF)
	@ $(CC) $(D_FLAG) $(CFLAG) $(CLIENT_SRC) $(FT_PRINTF) $(INC) -o $(CLIENT)
	@printf "$(_SUCCESS) client ready.\n"


$(FT_PRINTF):
	@ $(MAKE) DEBUG=$(DEBUG) -C ./FT_PRINTF

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

mandatory:	$(CLIENT) $(SERVER)
bonus:		mandatory

m : mandatory
b : bonus

.PHONY: all clean fclean re mandatory m bonus b
