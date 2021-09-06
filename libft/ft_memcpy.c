/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:30:52 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/05 19:49:36 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str_dst;
	unsigned char	*str_src;

	i = 0;
	str_dst = (unsigned char *)dst;
	str_src = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		str_dst[i] = str_src[i];
		i++;
	}
	return ((void *)dst);
}
