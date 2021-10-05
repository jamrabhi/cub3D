/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:33:00 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/27 23:36:00 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_cub(char *file_name)
{
	const char	*dot;

	dot = ft_strrchr(file_name, '.');
	if (ft_strncmp(dot, ".cub", 5) != 0)
		print_error("Incorrect file format");
}

int	check_elements(void)
{
	if (g_map.no_path && g_map.so_path && g_map.ea_path && g_map.we_path
		&& g_map.f[0] > -1 && g_map.c[0] > -1)
		return (1);
	return (0);
}

int	check_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
			return (0);
		i++;
	}
	return (1);
}

void	parse_line(char *file_cub)
{
	char	*line;
	int		ret;

	ret = 1;
	check_cub(file_cub);
	g_map.f[0] = -1;
	g_map.c[0] = -1;
	while (ret && check_elements() == 0)
	{
		ret = get_next_line(g_fd, &line);
		if ((!(get_no(line) || get_so(line) || get_we(line) || get_ea(line)
					|| get_f_c_rgb(line, 'F') || get_f_c_rgb(line, 'C')))
			&& !check_empty_line(line))
			print_error_n_free_line("Incorrect element in the .cub file", line);
		free(line);
	}
	if (!check_elements())
		print_error("Missing element in the .cub file");
	parse_map(line);
	close(g_fd);
}
