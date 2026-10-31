/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuqa134 <tuqa134@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:51:19 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/31 18:36:53 by fabo-ome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "Libft/libft.h"
# include "Printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int             index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	struct s_node	*head;
	int			size; // size data type was long idk why i changed it to int 
}					t_stack;
typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}					t_strategy;

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
}					t_opcounts;
typedef struct s_options
{
	t_stack			*a;
	t_stack			*b;
	t_strategy		strategy;
	double			disorder;
	int				bench;
	int				counter[TOTAL];
}					t_options;

t_node				*new_node(int value);
void				add_node(t_stack *stack, t_node *new);
void				free_stack(t_stack *stack);
void				sa(t_options *option);
void				sb(t_options *option);
void				ss(t_options *option);
void				pa(t_options *option);
void				pb(t_options *option);
void				ra(t_options *option);
void				rb(t_options *option);
void				rr(t_options *option);
void				rra(t_options *option);
void				rrb(t_options *option);
void				rrr(t_options *option);
void				swap(t_stack *p);
void				rotate(t_stack *p);
void				reverse_rotate(t_stack *p);
void				parse_args(int argc, char **argv, t_options *options);
void				free_split(char **res);
int					is_duplicate(t_node *stack, int val);
int					strnncmp(char *s1, char *s2);
int					parse_atoi(const char *str, int *value);
void				add_to_stack(char *num, t_options *options);
void				print_bench(t_options *option);
double				compute_disorder(t_stack *a);
void				startegy_selector(t_options *options);
void				selection_sort(t_options *options);
void				print_error(t_options *options);
void    assign_indexes(t_node *head);
void	radix_sort(t_options *options);
void	chunk_sort(t_options *options);



#endif
