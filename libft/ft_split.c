/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:04:28 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/05 19:52:43 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static char	**free_array(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
*/

static size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**rt;
	size_t	index;
	size_t	start;

	i = 0;
	index = 0;
	rt = (char **)malloc(sizeof(*rt) * (ft_count_words(s, c) + 1));
	if (!s || !rt)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			rt[index++] = ft_substr(s, start, (i - start));
		}
		else
			i++;
	}
	rt[index] = NULL;
	return (rt);
}
