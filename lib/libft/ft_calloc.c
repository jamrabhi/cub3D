/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:30:30 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/05 17:40:04 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*rt;

	i = 0;
	rt = malloc(count * size);
	if (!rt)
		return (NULL);
	while (i < (count * size))
	{
		((char *)rt)[i] = 0;
		i++;
	}
	return (rt);
}
