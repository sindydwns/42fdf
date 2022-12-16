/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:30:13 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/17 02:44:26 by yonshin          ###   ########.fr       */
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

static void	parse(t_map *m, int fd)
{
	int		x;
	int		y;
	char	*line;
	char	**col;

	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		col = ft_split(line, ' ');
		x = 0;
		while (col[x])
		{
			m->map[m->width * y + x] = ft_atoi(col[x]);
			free(col[x++]);
		}
		free(line);
		line = get_next_line(fd);
		y++;
	}
}

int	parse_map(const char *path, t_map *m)
{
	const int	fd = open(path, O_RDONLY);

	if (fd < 0)
		exit(1);
	m->height = get_height(path);
	m->width = get_width(path);
	m->map = malloc(sizeof(int) * m->width * m->height);
	if (m->map == 0)
		exit(1);
	parse(m, fd);
	close(fd);
	return (0);
}
