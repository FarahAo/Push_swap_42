/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opss.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:36:28 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/10/15 13:36:47 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void    swap(t_stack *p)
{
        t_node  *tmp;

        if (!p || !p->head || !p->head->next)
                return ;
        tmp = p->head;
        p->head = p->head->next;
        tmp->next = p->head->next;
        p->head->next = tmp;
}

void    rotate(t_stack *p)
{
        t_node  *tmp;
        t_node  *last;

        if (!p || !p->head || !p->head->next)
                return ;
        tmp = p->head;
        last = tmp;
        p->head = p->head->next;
        while (last->next)
                last = last->next;
        last->next = tmp;
        tmp->next = NULL;
}

void    reverse_rotate(t_stack *p)
{
        t_node  *tmp;
        t_node  *last;

        if (!p || !p->head || !p->head->next)
                return ;
        tmp = p->head;
        while (tmp->next->next)
                tmp = tmp->next;
        last = tmp->next;
        tmp->next = NULL;
        last->next = p->head;
        p->head = last;
}

