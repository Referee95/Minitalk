# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 09:01:55 by ykhalil-          #+#    #+#              #
#    Updated: 2023/03/01 11:56:27 by ykhalil-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client

SERVER = server

CLIENT_BONUS = client_bonus

SERVER_BONUS = server_bonus
CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_print.c \

OBJS = ${SRCS:.c=.o}


all : $(CLIENT) $(SERVER)

$(CLIENT) :	
		$(CC) $(CFLAGS) client.c -o $@

$(SERVER) : $(OBJS)
		$(CC) $(CFLAGS) server.c $< -o $@
		
bonus : $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS) :	
		$(CC) $(CFLAGS) client_bonus.c -o $@

$(SERVER_BONUS) : $(OBJS)
		$(CC) $(CFLAGS) server_bonus.c $< -o $@
clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re : fclean all