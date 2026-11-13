# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/12 14:52:10 by tkhaleel          #+#    #+#              #
#    Updated: 2026/11/12 14:52:17 by tkhaleel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c sort/chunk_sort.c sort/radix_sort.c sort/selection_sort.c stack_utils.c \
      operations/op1.c operations/op2.c operations/op3.c operations/operation_utils.c \
      parsing/parsing.c parsing/parsing_utils.c parsing/error.c parsing/split.c\
      strategy_bench_disorder/strategy_selector.c \
      strategy_bench_disorder/disorder.c strategy_bench_disorder/bench.c sort/sorting_helpers.c 

OBJ = $(SRC:.c=.o)



PRINTF_DIR = Printf

PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJ) $(PRINTF) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@


$(PRINTF):
	@$(MAKE) -s -C $(PRINTF_DIR)

clean:
	@rm -f $(OBJ)
	@$(MAKE) clean -s -C $(PRINTF_DIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -s -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re

