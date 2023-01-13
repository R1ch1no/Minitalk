# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 14:24:34 by rkurnava          #+#    #+#              #
#    Updated: 2023/01/13 19:13:54 by rkurnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Werror -Wextra -Wall

all :
	@$(CC) $(CFLAGS) -c server.c
	@$(CC) $(CFLAGS) -o server server.o
	@echo "Server created"

	@$(CC) $(CFLAGS) -c client.c
	@$(CC) $(CFLAGS) -o client client.o
	@echo "Client created"

clean:
	@rm -f client.o server.o
	@echo "Objects deleted"

fclean : clean
	@rm -f client server
	@echo "Client and server deleted"

re : fclean all

