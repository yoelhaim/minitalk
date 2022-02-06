# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 20:19:04 by yoelhaim          #+#    #+#              #
#    Updated: 2022/02/04 16:53:31 by yoelhaim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprint.a
FLAGS = -Wall -Wextra -Werror
ARC = ar rc
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
	@echo "succefully generat all"



