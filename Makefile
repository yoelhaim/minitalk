# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoelhaim <yoelhaim@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 20:19:04 by yoelhaim          #+#    #+#              #
#    Updated: 2022/01/02 20:32:09 by yoelhaim         ###   ########.fr        #
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
server : $(server_obj)
	@cc $(FLAGS) $(server_obj)  -o server
%.o: %.c
	@cc $(FLAGS) -c $< -o $@ 


