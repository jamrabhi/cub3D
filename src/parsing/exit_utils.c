/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:26:54 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/02/23 19:27:13 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_map(t_data *data)
{
	if (data->map)
	{
		free(data->map->no_path);
		free(data->map->so_path);
		free(data->map->we_path);
		free(data->map->ea_path);
		free_array(data->map->map_arr);
		free(data->map);
		if (data->map_fd != -1)
			close(data->map_fd);
	}
}

void	free_line(char *line, t_data *data)
{
	if (line)
		free(line);
	while (get_next_line(data->map_fd, &line))
		free(line);
	free(line);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		*array = NULL;
		if (array)
			free(array);
	}
}

int	free_array_and_return(char **array, int return_id)
{
	free_array(array);
	return (return_id);
}
