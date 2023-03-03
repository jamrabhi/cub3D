/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 00:37:22 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/04 18:36:42 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_array(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}

static int	free_exit(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
	return (-1);
}

static int	check_special_char(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] <= 0)
		{
			free(line);
			return (-1);
		}
		i++;
	}
	return (0);
}

static int	separate_lines(char **line, char **str, int fd)
{
	int		i;
	char	*rest;

	i = 0;
	while (str[fd][i] && str[fd][i] != '\n')
		i++;
	*line = ft_substr(str[fd], 0, i);
	if (check_special_char(*line) == -1)
		return (free_exit(&str[fd]));
	if (!line)
	{
		free_array(&str[fd]);
		return (-1);
	}
	if (str[fd][i])
	{
		rest = ft_substr(str[fd], i + 1, ft_strlen(str[fd]) - (i + 1));
		if (!rest)
			return (free_exit(&str[fd]));
		free_array(&str[fd]);
		str[fd] = rest;
		return (1);
	}
	free_array(&str[fd]);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*str[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			i;
	char		*tmp;

	if (!str[fd])
		str[fd] = (char *)ft_memalloc(sizeof(char) * 1);
	if (fd < 0 || fd >= OPEN_MAX || !line || BUFFER_SIZE <= 0
		|| read(fd, buf, 0) < 0 || !str[fd])
		return (-1);
	while (!ft_strchr(str[fd], '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i <= 0)
			break ;
		if (buf[0] == 0)
			return (free_exit(&str[fd]));
		buf[i] = '\0';
		tmp = ft_strjoin(str[fd], buf);
		if (!tmp)
			return (free_exit(&str[fd]));
		free_array(&str[fd]);
		str[fd] = tmp;
	}
	return (separate_lines(line, str, fd));
}
