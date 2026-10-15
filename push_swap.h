/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:51:19 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/13 19:21:16 by fabo-ome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h> //dont forget to remove when sumbitting 
#include <unistd.h>

typedef struct t_node
{
	int	value;
	struct t_node *next;
} s_node ;

typedef struct t_stack
{
	struct t_stack  *head;
} s_stack ;

s_node  *ft_lstnew(int value);
void    ft_lstadd_front(s_stack lst, s_node *new);
void	print_stack(s_node *node);
void	swap_sa(s_stack *a);
void	swap_sb(s_stack *b);
void	swap_ss(s_stack *a, s_stack *b);
void	pa(s_stack *a, s_stack *b);
void	pb(s_stack *a, s_stack *b);
void	ra(s_stack *a);
void	rb(s_stack *b);
void	rr(s_stack *a, s_stack *b);
void	swap(s_stack *p);
void	rotate(s_stack *p);











#endif
