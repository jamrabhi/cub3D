/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 22:17:04 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/05 19:54:42 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*rt;

	i = 0;
	while (s1[i])
		i++;
	rt = (char *)malloc(sizeof(char) * (i + 1));
	if (!rt)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		rt[i] = s1[i];
		i++;
	}
	rt[i] = '\0';
	return (rt);
}
