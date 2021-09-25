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

void	show_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		printf("Line[%d] = |%s|\n", i, array[i]);
		i++;
	}
}

static void free_array(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	if (str)
		free(str);
}

int	check_array(char **array)
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
	//char	*tmp;


	i = 1;
	str = array[1];
	while (array[i + 1])
	{
		ft_strlcat(str, array[i + 1], ((ft_strlen(str) + ft_strlen(array[i + 1]) + 1) * sizeof(char)));
		i++;
		//str = ft_strdup(tmp);
		//free(tmp);
		//printf("tmp = %s\n", tmp);
		//printf("str = %s\n", str);
	}
	//printf("tmp after = %s\n", tmp);
	//printf("str after = %s\n", str);
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

	if (map->f[0] == -1)
	{
		numbers = ft_split(line, ' ');

		if (line && (check_array(numbers) > 2)
				&& (ft_strncmp(numbers[0], "F", 2) == 0))
		{
			rgb_s = ft_strdup(join_array(numbers));
			free_array(numbers);
			numbers = ft_split(rgb_s, ',');
			size = check_array(numbers);
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
			free_array(numbers);
			free(rgb_s);
			return (1);
		}
		free_array(numbers);
	}
	return (0);
}

int	get_c_rgb(const char *line, t_map *map)
{
	char	**numbers;
	int		size;
	char	*rgb_s;

	if (map->c[0] == -1)
	{
		numbers = ft_split(line, ' ');
		if (line && (check_array(numbers) > 2) &&
			(ft_strncmp(numbers[0], "C", 2) == 0))
		{
			rgb_s = ft_strdup(join_array(numbers));
			free_array(numbers);
			numbers = ft_split(rgb_s, ',');
			size = check_array(numbers);
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
			free_array(numbers);
			free(rgb_s);
			return (1);
		}
		free_array(numbers);
	}
	return (0);
}
