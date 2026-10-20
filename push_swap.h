/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuqa134 <tuqa134@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:51:19 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/19 17:00:02 by tkhaleel         ###   ########.fr       */
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
}	t_stack;
typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

/*typedef  op_counts
{
	int SA;
	int SB;
	int SS;
	int PA;
	int PB;
	int RA;
	int RB;
	int RR;
	int RRA;
	int RRB;
	int RRR;
	int TOTAL;
}	t_opcounts; */
typedef struct s_options
{
	t_stack  a;
	t_stack  b;
	t_strategy	strategy;
	int			bench;
}	t_options;

t_node				*new_node(int value);
void				add_node(t_stack *lst, t_node *new);
void				print_stack(t_node *node);
void				swap_sa(t_stack *a);
void				swap_sb(t_stack *b);
void				swap_ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
void				swap(t_stack *p);
void				rotate(t_stack *p);
void				reverse_rotate(t_stack *p);
void                free_split(char **res);
#endif
