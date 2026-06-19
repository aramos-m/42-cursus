# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/19 23:01:07 by aramos-m          #+#    #+#              #
#    Updated: 2026/06/19 23:01:07 by aramos-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### VARIABLES ###

NAME		= philo

CC          = cc

CFLAGS      = -Wall -Wextra -Werror -pthread

RM          = rm -f

### FUENTES ###

SRCS        = main.c \
              utils.c

OBJS        = $(SRCS:.c=.o)

HEADER      = philo.h

### REGLAS ###

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
