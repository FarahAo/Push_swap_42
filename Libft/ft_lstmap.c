/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 13:53:05 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/09/11 14:19:23 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*nd;

	if (!lst || !del)
		return (NULL);
	new = NULL;
	nd = NULL;
	while (lst)
	{
		if (!f)
			nd = ft_lstnew(lst->content);
		else
			nd = ft_lstnew(f(lst->content));
		if (!nd)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, nd);
		lst = lst->next;
	}
	return (new);
}
