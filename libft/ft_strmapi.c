/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:50:49 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/05 19:58:48 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*rt;

	i = 0;
	rt = ft_strdup(s);
	if (!s || !f || !rt)
		return (NULL);
	while (s[i])
	{
		rt[i] = f(i, rt[i]);
		i++;
	}
	return (rt);
}
