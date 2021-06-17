/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:39:25 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/17 16:20:27 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_map
{
	char *NO_path;
	char *SO_path;
	char *WE_path;
	char *EA_path;
	int F[3];
	int C[3];
}				t_map;


int	get_line(char *file_cub, t_map *map);

#endif
