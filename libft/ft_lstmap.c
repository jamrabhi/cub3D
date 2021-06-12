/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 02:32:46 by jamrabhi          #+#    #+#             */
/*   Updated: 2019/10/30 03:43:38 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *newlst;
	t_list *beglst;

	if (!lst || !f)
		return (NULL);
	if (!(newlst = ft_lstnew(f(lst->content))))
		return (NULL);
	beglst = newlst;
	while (lst->next)
	{
		lst = lst->next;
		if (!(newlst->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&beglst, del);
			return (NULL);
		}
		newlst = newlst->next;
	}
	return (beglst);
}
