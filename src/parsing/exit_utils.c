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
	if (data->map_arr != NULL)
	{
		free(data->no_path);
		free(data->so_path);
		free(data->we_path);
		free(data->ea_path);
		free_split(data->map_arr);
		if (data->map_fd > 0)
			close(data->map_fd);
		if (data->NO_fd > 0)
			close(data->NO_fd);
		if (data->SO_fd > 0)
			close(data->SO_fd);
		if (data->WE_fd > 0)
			close(data->WE_fd);
		if (data->EA_fd > 0)
			close(data->EA_fd);
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
	if (array != NULL)
		return ;
	while (array[i] != NULL)
		free(array[i++]);
	free(array);
}

int	free_array_and_return(char **array, int return_id)
{
	free_split(array);
	return (return_id);
}
