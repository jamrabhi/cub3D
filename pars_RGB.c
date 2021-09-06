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

int	get_F_RGB(const char *line, t_map *map)
{
	char	**numbers;
	int		RGB[3];
	int		size;
	char	*RGB_s;

	numbers = ft_split(line, ' ');
	if (line && numbers[0] && (ft_strncmp(numbers[0], "F", 1) == 0))
	{
		RGB_s = join_array(numbers);
		numbers = ft_split(RGB_s, ',');
		size = check_number_elements(numbers);
		if (!(size == 3 && check_commas(RGB_s) == 2 && ft_isdigit_str
				(numbers[0]) && ft_isdigit_str(numbers[1]) && ft_isdigit_str
				(numbers[2]) && map->F[0] == -1))
			print_error("Fichier .cub incorrect");
		RGB[0] = ft_atoi(numbers[0]);
		RGB[1] = ft_atoi(numbers[1]);
		RGB[2] = ft_atoi(numbers[2]);
		if (!((RGB[0] >= 0 && RGB[0] <= 255) && (RGB[1] >= 0 && RGB[1] <= 255)
				&& (RGB[2] >= 0 && RGB[2] <= 255)))
			print_error("Fichier .cub incorrect");
		map->F[0] = RGB[0];
		map->F[1] = RGB[1];
		map->F[2] = RGB[2];
		return (1);
	}
	return 0;
}

int	get_C_RGB(const char *line, t_map *map)
{
	char	**numbers;
	int		RGB[3];
	int		size;
	char	*RGB_s;

	numbers = ft_split(line, ' ');
	if (line && numbers[0] && (ft_strncmp(numbers[0], "C", 1) == 0))
	{
		RGB_s = join_array(numbers);
		numbers = ft_split(RGB_s, ',');
		size = check_number_elements(numbers);
		if (!(size == 3 && check_commas(RGB_s) == 2 && ft_isdigit_str
				(numbers[0]) && ft_isdigit_str(numbers[1]) && ft_isdigit_str
				(numbers[2]) && map->C[0] == -1))
			print_error("Fichier .cub incorrect");
		RGB[0] = ft_atoi(numbers[0]);
		RGB[1] = ft_atoi(numbers[1]);
		RGB[2] = ft_atoi(numbers[2]);
		if (!((RGB[0] >= 0 && RGB[0] <= 255) && (RGB[1] >= 0 && RGB[1] <= 255)
				&& (RGB[2] >= 0 && RGB[2] <= 255)))
			print_error("Fichier .cub incorrect");
		map->C[0] = RGB[0];
		map->C[1] = RGB[1];
		map->C[2] = RGB[2];
		return (1);
	}
	return 0;
}
