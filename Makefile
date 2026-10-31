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

CFILES =  opertaions/op1.c operations/op2.c operations/op3.c \
	operations\operation_utils.c parsing\parsing.c parsing\parsing_utils.c \
	strategy_bench_disorder/bench.c strategy_bench_disorder/disorder.c \
	strategy_bench_disorder/strategy_selector.c selection_sort.c stack_utils.c \
	

OBJ = $(CFILES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = Printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

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
