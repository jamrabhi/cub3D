/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 00:27:51 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/10/06 00:27:53 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_error(char *error)
{
	printf("Error : %s\n", error);
	free(g_map.no_path);
	free(g_map.so_path);
	free(g_map.we_path);
	free(g_map.ea_path);
	exit (EXIT_FAILURE);
}

void	free_array(char **str)
{
	int	i;

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

int	free_array_and_return(char **array, int return_id)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	*array = NULL;
	if (array)
		free(array);
	return (return_id);
}

int	print_error_n_free_line(char *error, char *line)
{
	printf("Error : %s\n", error);
	if (line)
		free(line);
	while (get_next_line(g_fd, &line))
		free(line);
	free(line);
	free(g_map.no_path);
	free(g_map.so_path);
	free(g_map.we_path);
	free(g_map.ea_path);
	close(g_fd);
	exit (EXIT_FAILURE);
}

int	print_error_n_free_array_n_line(char *error, char **array, char *line)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	*array = NULL;
	if (array)
		free(array);
	if (line)
	{
		free(line);
		while (get_next_line(g_fd, &line))
			free(line);
		free(line);
	}
	free(g_map.no_path);
	free(g_map.so_path);
	free(g_map.we_path);
	free(g_map.ea_path);
	close(g_fd);
	printf("Error : %s\n", error);
	exit (EXIT_FAILURE);
}
