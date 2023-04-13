# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/03 17:45:40 by vinograd          #+#    #+#              #
#    Updated: 2019/08/31 17:09:21 by Nik              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: test

NAME=libft.a

SRCS=*.c 

OBJECTS=*.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS)
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

test: main.c get_next_line.c get_next_line.h
	cc *.c -o test
	./test

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
