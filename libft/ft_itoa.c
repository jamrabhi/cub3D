/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:57:41 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/05 19:39:10 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
		len++;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*rt;
	unsigned int	nb_cpy;
	size_t			len;

	nb_cpy = n;
	len = ft_intlen(n);
	rt = (char *)malloc(sizeof(*rt) * (len + 1));
	if (!rt)
		return (NULL);
	rt[len--] = '\0';
	if (n < 0)
	{
		nb_cpy = n * -1;
		rt[0] = '-';
	}
	if (nb_cpy == 0)
		rt[len] = 0 + '0';
	while (nb_cpy != 0)
	{
		rt[len--] = (nb_cpy % 10 + '0');
		nb_cpy = nb_cpy / 10;
	}
	return (rt);
}
