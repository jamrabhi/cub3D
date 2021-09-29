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

int	check_format_first(const char *line, char c)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] != c && line[i + 1] != ' ')
		return (-1);
	i += 2;
	while (line[i] == ' ')
		i++;
	if (line[i] && !ft_isdigit(line[i]))
		return (-1);
	return (i);
}

int	skip_digit_and_space(const char *line, int i)
{
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	return (i);
}

int	check_format(const char *ln, char c)
{
	int	i;
	int	nb_and_commas;

	i = check_format_first(ln, c);
	nb_and_commas = 0;
	while (ln[i])
	{
		if (ln[i] && ft_isdigit(ln[i]))
			nb_and_commas++;
		i = skip_digit_and_space(ln, i);
		if (ln[i] && (!ft_isdigit(ln[i]) && ln[i] != ',' && ln[i] != ' '))
			return (-1);
		if (ln[i] && ln[i] == ',')
		{
			i++;
			nb_and_commas++;
			while (ln[i] == ' ')
				i++;
			if (!ln[i] || (ln[i] && !ft_isdigit(ln[i])))
				return (-1);
		}
	}
	if (nb_and_commas != 5)
		return (-1);
	return (0);
}

int	get_f_c_rgb(char *line, t_map *map, char c)
{
	char	**tmp;
	int		i;
	int		stock;

	i = 1;
	tmp = ft_split_str(line, " ,");
	if (tmp[0] && ((c == 'F' && ft_strcmp(tmp[0], "F") == 0 && map->f[0] == -1)
			|| (c == 'C' && ft_strcmp(tmp[0], "C") == 0 && map->c[0] == -1)))
	{
		if (check_format(line, c) == -1)
			print_error_n_free_array_n_line("Incorrect RGB", tmp, line, fd);
		while (tmp[i])
		{
			stock = ft_atoi(tmp[i]);
			if (stock < 0 || stock > 255)
				print_error_n_free_array_n_line("Incorrect RGB", tmp, line, fd);
			if (c == 'F')
				map->f[i - 1] = stock;
			if (c == 'C')
				map->c[i - 1] = stock;
			i++;
		}
		return (free_array_and_return(tmp, 1));
	}
	return (free_array_and_return(tmp, 0));
}
