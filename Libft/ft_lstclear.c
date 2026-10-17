/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 11:28:14 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/09/22 16:23:34 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nextn;

	if (!lst || !del || !*lst)
		return ;
	while (*lst)
	{
		nextn = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nextn;
	}
	*lst = NULL;
}
