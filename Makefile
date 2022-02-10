# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 20:19:04 by yoelhaim          #+#    #+#              #
#    Updated: 2022/02/08 12:10:10 by yoelhaim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
ARC = ar rc
RMV = rm -rf
SRC_S = server.c
SRC_C = client.c
client_obj = $(SRC_C:.c=.o)
server_obj = $(SRC_S:.c=.o)
all : client server
client : $(client_obj)
	@cc $(FLAGS) $(client_obj) -o client
	@echo "succefully generat client"
server : $(server_obj)
	@cc $(FLAGS) $(server_obj)  -o server
	@echo "succefully generat server"
%.o: %.c
	@cc $(FLAGS) -c $< -o $@
clean:
	@$(RMV) $(client_obj) $(server_obj) client server
	@echo "succefully deleted all"
PHONY: client server all

