# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 20:19:04 by yoelhaim          #+#    #+#              #
#    Updated: 2022/02/15 16:21:14 by yoelhaim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
ARC = ar rc
RMV = rm -rf
SRC_S = server.c
SRC_C = client.c
client_obj = $(SRC_C:.c=.o)
server_obj = $(SRC_S:.c=.o)

SRC_S_B = server_bonus.c
SRC_C_B = client_bonus.c
client_obj_b = $(SRC_C_B:.c=.o)
server_obj_b = $(SRC_S_B:.c=.o)

all : client server
client : $(client_obj)
	@cc $(FLAGS) $(client_obj) -o client
	@echo "succefully generat client"
server : $(server_obj)
	@cc $(FLAGS) $(server_obj)  -o server
	@echo "succefully generat server"
client_bonus : $(client_obj_b)
	@cc $(FLAGS) $(client_obj_b) -o client_bonus
	@echo "succefully generat client bonus"
server_bonus : $(server_obj_b)
	@cc $(FLAGS) $(server_obj_b)  -o server_bonus
	@echo "succefully generat server bonus"
%.o: %.c
	@cc $(FLAGS) -c $< -o $@
bonus: client_bonus server_bonus
clean:
	@$(RMV) $(client_obj) $(server_obj) client server \
	$(client_obj_b) $(server_obj_b) client_bonus server_bonus
	@echo "succefully deleted all"
PHONY: client server all

