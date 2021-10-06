/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:42:20 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/05 19:50:24 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*str_dst;
	unsigned char	*str_src;

	str_dst = (unsigned char *)dst;
	str_src = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (str_dst < str_src)
	{
		i = -1;
		while (++i < len)
			str_dst[i] = str_src[i];
	}
	else
	{
		i = len;
		while (i > 0)
		{
			i--;
			str_dst[i] = str_src[i];
		}
	}
	return (dst);
}
