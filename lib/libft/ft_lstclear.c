/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 01:55:02 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/05 19:39:48 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;
	t_list	*tmp;

	list = *lst;
	if (lst)
	{
		while (list)
		{
			if (list->next)
				tmp = list->next;
			else
				tmp = NULL;
			ft_lstdelone(list, del);
			list = tmp;
		}
	}
	*lst = NULL;
}
