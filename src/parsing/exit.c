/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:35:17 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/02/23 19:35:20 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	exit_error(char *error, t_data *data)
{
	printf("Error : %s\n", error);
	free_mlx(data);
	free_map_file(data);
	exit (EXIT_FAILURE);
}

int	exit_error_n_free_line(char *error, char *line, t_data *data)
{
	printf("Error : %s\n", error);
	free_line(line, data);
	free_map_file(data);
	exit (EXIT_FAILURE);
}

int	exit_error_n_free_array_n_line(char *error, char **array, char *line,
	t_data *data)
{
	printf("Error : %s\n", error);
	free_split(array);
	free_line(line, data);
	free_map_file(data);
	exit (EXIT_FAILURE);
}
