/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:30:13 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/13 18:45:54 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include "libft.h"

static int	get_height(const char *path)
{
	const int	fd = open(path, O_RDONLY);
	char		*line;
	int			height;

	if (fd < 0)
		exit(1);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		height++;
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

static int	get_width(const char *path)
{
	const int	fd = open(path, O_RDONLY);
	char		*line;
	char		**col;
	int			width;

	if (fd < 0)
		exit(1);
	width = 0;
	line = get_next_line(fd);
	if (line == 0)
		exit(1);
	col = ft_split(line, ' ');
	if (col == 0)
		exit(1);
	while (col[width])
		free(col[width++]);
	free(col);
	free(line);
	close(fd);
	return (width);
}

static void	init(t_map *m, const char *path)
{
	m->height = get_height(path);
	m->width = get_width(path);
	m->map = malloc(sizeof(int) * m->width * m->height);
	if (m->map == 0)
		exit(1);
}

int	parse_map(const char *path, t_map *m)
{
	const int	fd = open(path, O_RDONLY);
	char		*line;
	char		**col;

	if (fd < 0)
		exit(1);
	init(m, path);
	line = get_next_line(fd);
	m->height = 0;
	while (line)
	{
		col = ft_split(line, ' ');
		m->width = 0;
		while (col[m->width])
		{
			m->map[m->height * m->width + m->width] = ft_atoi(col[m->width]);
			free(col[m->width++]);
		}
		free(line);
		line = get_next_line(fd);
		m->height++;
	}
	close(fd);
	return (0);
}
