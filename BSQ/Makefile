# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhomer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/18 16:00:04 by jhomer            #+#    #+#              #
#    Updated: 2019/07/18 16:00:08 by jhomer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEAD=bsq.h
SRC=*.c
CC=gcc
CFLAGS=-Wall -Wextra -Werror
PNAME=bsq

all:
	gcc  $(CFLAGS) -o $(PNAME) $(SRC)
		
clean:
	rm -rf *.o

fclean: clean
	rm -rf $(PNAME)

re: fclean all

