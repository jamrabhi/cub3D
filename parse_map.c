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
				|| str[i] == 'E' || str[i] == 'W' || str[i] == '\n'
				|| str[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

int	check_max_length(char *str)
{
	int	i;
	int	counter;
	int	max_length;

	i = 0;
	counter = 0;
	max_length = 0;
	while (str[i])
	{
		i++;
		if (str[i - 1] != '\n' && str[i - 1] != ' ') //&& check_valid_char(&str[i-1]))
			counter++;
		if (max_length < counter)
			max_length = counter;
		if (str[i] == '\n')
		{
			counter = 0;
			i++;
		}
	}
	return (max_length);
}

void	parse_map(char *str, t_map *map)
{
	if (map)
		ft_isprint('0');
	if (check_valid_char(str) == 0)
		print_error("Invalid map");
	printf("max = %d", check_max_length(str));
}
