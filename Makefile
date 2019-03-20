# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/27 18:40:56 by dbolilyi          #+#    #+#              #
#    Updated: 2018/05/01 17:07:09 by dbolilyi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

HEADER = structures.h

SRC = \
SRCS/helpers1.c \
SRCS/helpers2.c \
SRCS/mem_lst.c \
SRCS/readnfind.c \
SRCS/validation.c

OBJ = \
helpers1.o \
helpers2.o \
mem_lst.o \
readnfind.o \
validation.o

FL = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	gcc $(FL) -c $(SRC) -I $(HEADER)
	gcc $(FL) -o $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean \
	all
