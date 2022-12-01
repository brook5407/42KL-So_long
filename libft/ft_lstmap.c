/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:12:13 by chchin            #+#    #+#             */
/*   Updated: 2022/05/17 10:15:19 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*address;

	if (!lst)
		return (0);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (0);
	lst = lst->next;
	address = new;
	while (lst)
	{
		new->next = ft_lstnew(f(lst->content));
		if (!new->next)
		{
			ft_lstclear(&address, del);
			return (0);
		}
		new = new->next;
		lst = lst->next;
	}
	new->next = NULL;
	return (address);
}
