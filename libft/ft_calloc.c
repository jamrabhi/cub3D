/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:30:30 by jamrabhi          #+#    #+#             */
/*   Updated: 2019/10/18 00:28:40 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*rt;

	i = 0;
	if (!(rt = malloc(count * size)))
		return (NULL);
	while (i < (count * size))
	{
		((char*)rt)[i] = 0;
		i++;
	}
	return (rt);
}
