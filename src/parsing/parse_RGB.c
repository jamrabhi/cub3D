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

#include <cub3D.h>

int	check_format_first(char *line, char c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line);
	while (i < len && line[i] == ' ')
		i++;
	if (i >= len || (line[i] != c && line[i + 1] != ' '))
		return (-1);
	i += 2;
	while (i < len && line[i] == ' ')
		i++;
	if (i >= len || (line[i] && !ft_isdigit(line[i])))
		return (-1);
	return (i);
}

int	skip_digit_and_space(char *line, int i)
{
	int	len;

	len = ft_strlen(line);
	while (i < len && ft_isdigit(line[i]))
		i++;
	while (i < len && line[i] == ' ')
		i++;
	return (i);
}

int	check_format(char *ln, char c)
{
	int	i;
	int	nb_and_commas;

	i = check_format_first(ln, c);
	nb_and_commas = 0;
	while (i != -1 && i < (int)ft_strlen(ln) && ln[i])
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

int	get_f_c_rgb(char *line, char c, t_data *data)
{
	char	**tmp;
	int		i;
	long	stock;

	i = 0;
	tmp = ft_split_str(line, " ,");
	if (tmp[0] && ((c == 'F' && ft_strcmp(tmp[0], "F") == 0
				&& data->floor[0] == -1) || (c == 'C' && ft_strcmp(tmp[0], "C")
				== 0 && data->ceiling[0] == -1)))
	{
		if (check_format(line, c) == -1)
			exit_error_n_free_array_n_line(INVALID_RGB, tmp, line, data);
		while (tmp[++i])
		{
			stock = ft_atol(tmp[i]);
			if (stock < 0 || stock > 255)
				exit_error_n_free_array_n_line(INVALID_RGB, tmp, line, data);
			if (c == 'F')
				data->floor[i - 1] = stock;
			if (c == 'C')
				data->ceiling[i - 1] = stock;
		}
		return (free_array_and_return(tmp, 1));
	}
	return (free_array_and_return(tmp, 0));
}
