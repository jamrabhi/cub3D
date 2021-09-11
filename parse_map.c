/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 19:22:18 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/09/08 19:22:22 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_valid_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == '0' || str[i] == '1' || str[i] == 'N' || str[i] == 'S'
				|| str[i] == 'E' || str[i] == 'W' || str[i] == '\n'))
			return (0);
		i++;
	}
	return (1);
}

void	parse_map(char *str, t_map *map)
{
	if (map)
		ft_isprint('0');
	if (check_valid_char(str) == 0)
		print_error("Invalid map");
}
