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

void	free_map_file(t_data *data)
{
	if (data)
	{
		free(data->no_path);
		free(data->so_path);
		free(data->we_path);
		free(data->ea_path);
		free_split(data->map_arr);
		if (data->map_fd > 0)
			close(data->map_fd);
		if (data->no_fd > 0)
			close(data->no_fd);
		if (data->so_fd > 0)
			close(data->so_fd);
		if (data->we_fd > 0)
			close(data->we_fd);
		if (data->ea_fd > 0)
			close(data->ea_fd);
	}
}

void	free_line(char *line, t_data *data)
{
	if (line != NULL)
		free(line);
	while (get_next_line(data->map_fd, &line))
		free(line);
	free(line);
}

void	free_split(char **array)
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
	free_split(array);
	return (return_id);
}
