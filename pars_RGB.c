/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_RGB.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 23:11:45 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/27 23:37:12 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_number_elements(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	*join_array(char **array)
{
	int		i;
	char	*str;

	i = 1;
	str = array[1];
	while (array[i + 1])
	{
		str = ft_strjoin(str, array[i + 1]);
		i++;
	}
	return (str);
}

int	check_commas(char *str)
{
	int	i;
	int	rt;

	i = 0;
	rt = 0;
	while (str[i])
	{
		if (str[i] == ',')
			rt++;
		i++;
	}
	return (rt);
}

int	get_f_rgb(const char *line, t_map *map)
{
	char	**numbers;
	int		size;
	char	*rgb_s;

	numbers = ft_split(line, ' ');
	if (line && numbers[0] && (ft_strncmp(numbers[0], "F", 1) == 0))
	{
		rgb_s = join_array(numbers);
		numbers = ft_split(rgb_s, ',');
		size = check_number_elements(numbers);
		if (!(size == 3 && check_commas(rgb_s) == 2 && ft_isdigit_str
				(numbers[0]) && ft_isdigit_str(numbers[1]) && ft_isdigit_str
				(numbers[2]) && map->f[0] == -1))
			print_error("Misconfiguration in the .cub scene (Floor color)");
		map->f[0] = ft_atoi(numbers[0]);
		map->f[1] = ft_atoi(numbers[1]);
		map->f[2] = ft_atoi(numbers[2]);
		if (!((map->f[0] >= 0 && map->f[0] <= 255) && (map->f[1] >= 0 && map
					->f[1] <= 255) && (map->f[2] >= 0 && map->f[2] <= 255)))
			print_error("Misconfiguration in the .cub scene (Floor color)");
		return (1);
	}
	return (0);
}

int	get_c_rgb(const char *line, t_map *map)
{
	char	**numbers;
	int		size;
	char	*rgb_s;

	numbers = ft_split(line, ' ');
	if (line && numbers[0] && (ft_strncmp(numbers[0], "C", 1) == 0))
	{
		rgb_s = join_array(numbers);
		numbers = ft_split(rgb_s, ',');
		size = check_number_elements(numbers);
		if (!(size == 3 && check_commas(rgb_s) == 2 && ft_isdigit_str
				(numbers[0]) && ft_isdigit_str(numbers[1]) && ft_isdigit_str
				(numbers[2]) && map->c[0] == -1))
			print_error("Misconfiguration in the .cub scene (Ceiling color)");
		map->c[0] = ft_atoi(numbers[0]);
		map->c[1] = ft_atoi(numbers[1]);
		map->c[2] = ft_atoi(numbers[2]);
		if (!((map->c[0] >= 0 && map->c[0] <= 255) && (map->c[1] >= 0 && map
					->c[1] <= 255) && (map->c[2] >= 0 && map->c[2] <= 255)))
			print_error("Misconfiguration in the .cub scene (Ceiling color)");
		return (1);
	}
	return (0);
}
