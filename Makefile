# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 20:19:04 by yoelhaim          #+#    #+#              #
#    Updated: 2022/02/19 22:04:16 by yoelhaim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = minitalk
FLAGS = -Wall -Wextra -Werror
RMV = rm -rf
HEADER = utils.h

SRC_UTILS= utils_mini.c
utils_obj = $(SRC_UTILS:.c=.o)

SRC_S = server.c
SRC_C = client.c

client_obj = $(SRC_C:.c=.o)
server_obj = $(SRC_S:.c=.o)

SRC_S_B = server_bonus.c
SRC_C_B = client_bonus.c
client_obj_b = $(SRC_C_B:.c=.o)
server_obj_b = $(SRC_S_B:.c=.o)

$(NAME): $(utils_obj) $(client_obj) $(server_obj)
	@$(CC) $(CFLAGS) $(utils_obj) $(server_obj)  -o server
	@$(CC) $(CFLAGS) $(utils_obj) $(client_obj)  -o client
	@echo "successfelly generate "
all : $(NAME)
%.o:%.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

bonus: $(utils_obj) $(client_obj_b) $(server_obj_b)
	@$(CC) $(CFLAGS) $(utils_obj) $(server_obj_b)  -o server_bonus
	@$(CC) $(CFLAGS) $(utils_obj) $(client_obj_b)  -o client_bonus
	@echo "successfelly generate bonus "

clean:
	@$(RMV) $(client_obj) $(server_obj) $(client_obj_b) $(server_obj_b) $(utils_obj)
	@echo "succefully deleted "

fclean: clean
	 @$(RMV) client server client_bonus server_bonus
	 @echo "succefully deleted all"
re : fclean $(NAME)
PHONY: clean fclean all re bonus
