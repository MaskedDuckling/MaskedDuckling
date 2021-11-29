# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eydupray <eydupray@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 15:22:06 by eydupray          #+#    #+#              #
#    Updated: 2021/11/29 15:48:50 by eydupray         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = clang
INC = philo.h
CFLAGS = -Wall -Werror -Wextra

SRCS	=	main.c utils.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(FLAGS)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re