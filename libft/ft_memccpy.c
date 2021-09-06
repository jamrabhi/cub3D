/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:43:51 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/05 19:46:21 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*str_dst;
	unsigned char	*str_src;
	unsigned char	ch;

	i = 0;
	str_dst = (unsigned char *)dst;
	str_src = (unsigned char *)src;
	ch = (unsigned char)c;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		str_dst[i] = str_src[i];
		i++;
		if (str_src[i] == ch)
		{
			str_dst[i] = str_src[i];
			return (dst + i + 1);
		}
	}
	return (NULL);
}
