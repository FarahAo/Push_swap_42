/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuqa134 <tuqa134@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:51:19 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/23 16:09:09 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "Libft/libft.h"
# include "Printf/ft_printf.h"
# include <stdio.h> //delete later 
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	struct s_node	*head;
	long	 size;
}	t_stack;
typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

typedef enum e_op_counts
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	TOTAL
}	t_opcounts;
typedef struct s_options
{
	t_stack  a;
	t_stack  b;
	t_strategy	strategy;
	int			bench;
	double disorder;
	int counter[TOTAL];
}	t_options;

t_node				*new_node(int value);
void				add_node(t_stack *lst, t_node *new);
void				print_stack(t_node *a);
void	swap_sa(t_options *option);
void	swap_sb(t_options *option);
void	swap_ss(t_options *option);
void	pa(t_options *option);
void	pb(t_options *option);
void	ra(t_options *option);
void	rb(t_options *option);
void	rr(t_options *option);
void	rra(t_options *option);
void	rrb(t_options *option);
void	rrr(t_options *option);
void				swap(t_stack *p);
void				rotate(t_stack *p);
void				reverse_rotate(t_stack *p);
void                free_split(char **res);
void				free_stack(t_stack *stack);
int					is_duplicate(t_node *stack, int val);
int					strnncmp(char *s1, char *s2);
int     			parse_atoi(const char *str, int *value);
double				compute_disorder(t_stack *a);
void    parse_args(int argc, char **argv,t_options *options);
void    print_bench(t_options *option);
#endif
