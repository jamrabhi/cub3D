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
		i++;
	}
	*str = NULL;
	if (str)
		free(str);
}

char				**ft_clear_splitted(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static unsigned int	ft_get_nb_strs(char const *s, const char *delimiters)
{
	unsigned int	i;
	unsigned int	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && ft_strchr(delimiters, s[i]))
		i++;
	while (s[i])
	{
		if (ft_strchr(delimiters, s[i]))
		{
			nb_strs++;
			while (s[i] && ft_strchr(delimiters, s[i]))
				i++;
			continue ;
		}
		i++;
	}
	if (!ft_strchr(delimiters, s[i - 1]))
		nb_strs++;
	return (nb_strs);
}

static void			ft_get_next_str(char **next_str, unsigned int *next_str_len,
					const char *delimiters)
{
	unsigned int i;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = 0;
	while (**next_str && ft_strchr(delimiters, **next_str))
		(*next_str)++;
	while ((*next_str)[i])
	{
		if (ft_strchr(delimiters, (*next_str)[i]))
			return ;
		(*next_str_len)++;
		i++;
	}
}

char				**ft_split__(char const *s, const char *delimiters)
{
	char			**tab;
	char			*next_str;
	unsigned int	next_str_len;
	unsigned int	nb_strs;
	unsigned int	i;

	nb_strs = ft_get_nb_strs(s, delimiters);
	if (!(tab = malloc(sizeof(char *) * (nb_strs + 1))))
		return (NULL);
	i = 0;
	next_str = (char *)s;
	next_str_len = 0;
	while (i < nb_strs)
	{
		ft_get_next_str(&next_str, &next_str_len, delimiters);
		if (!(tab[i] = malloc(sizeof(char) * (next_str_len + 1))))
			return (ft_clear_splitted(tab));
		ft_strlcpy(tab[i], next_str, next_str_len + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int	check_format_first(char *line, char c)
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

int	check_format(char *line, char c)
{
	int i;
	int	nb_and_commas;

	i = check_format_first(line, c);
	nb_and_commas = 0;
	if (i == -1)
		return (-1);
	while (line[i])
	{
		if (line[i] && ft_isdigit(line[i]))
			nb_and_commas++;
		while (line[i] && ft_isdigit(line[i]))
			i++;
		while (line[i] == ' ')
			i++;
		if (line[i] && line[i] == ',')
		{
			i++;
			nb_and_commas++;
				while(line[i] == ' ')
					i++;
			if (!line[i] || (line[i] && !ft_isdigit(line[i])))
				return (-1);
		}
		// else if (nb_and_commas != 5)
		// 	return (-1);
	}
	if (nb_and_commas != 5)
		return (-1);
	return (0);
}

int	get_f_c_rgb(char *line, t_map *map, char c)
{
	char **tmp;
	int	i;
	int	stock;

	i = 1;
	tmp = ft_split__(line, " ,");
	if (tmp[0] && ((c == 'F' && ft_strcmp(tmp[0], "F") == 0 && map->f[0] == -1)
			|| (c == 'C' && ft_strcmp(tmp[0], "C") == 0 && map->c[0] == -1)))
	{
		if (check_format(line, c) == -1)
			print_error_n_free_array("Incorrect RGB settings", tmp);
		while (tmp[i])
		{
			stock = ft_atoi(tmp[i]);
			if (stock < 0 || stock > 255)
				print_error_n_free_array("Incorrect RGB settings", tmp);
				
			if (c == 'F')
				map->f[i- 1] = stock;
			if (c == 'C')
				map->c[i- 1] = stock;
			i++;
		}
		free_array(tmp);
		return (1);
	}
	free_array(tmp);
	return (0);
}
