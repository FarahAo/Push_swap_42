# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/29 17:58:23 by tkhaleel          #+#    #+#              #
#    Updated: 2026/11/10 16:32:30 by fabo-ome         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c print_char.c print_hex.c print_nbr.c print_ptr.c print_str.c print_unbr.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)


fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
