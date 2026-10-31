# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tuqa134 <tuqa134@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/13 16:37:21 by fabo-ome          #+#    #+#              #
#    Updated: 2026/10/29 02:33:57 by fabo-ome         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

SRC = main.c chunk_sort.c radix_sort.c selection_sort.c stack_utils.c \
      operations/op1.c operations/op2.c operations/op3.c operations/operation_utils.c \
      parsing/parsing.c parsing/parsing_utils.c parsing/error.c \
      strategy_bench_disorder/strategy_selector.c \
      strategy_bench_disorder/disorder.c strategy_bench_disorder/bench.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = Libft

LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = Printf

PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re

