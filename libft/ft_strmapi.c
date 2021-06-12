/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:50:49 by jamrabhi          #+#    #+#             */
/*   Updated: 2019/10/30 22:39:37 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*rt;

	i = 0;
	if (!s || !f || !(rt = ft_strdup(s)))
		return (NULL);
	while (s[i])
	{
		rt[i] = f(i, rt[i]);
		i++;
	}
	return (rt);
}
