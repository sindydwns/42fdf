/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:30:13 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/28 10:23:49 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include "libft.h"
#include "myutil.h"

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
	while (col[width] && (*col[width] == '-' || ft_isdigit(*col[width])))
		free(col[width++]);
	free(col);
	free(line);
	close(fd);
	return (width);
}

static void	parse(t_obj *ob, int fd, int w, int h)
{
	const t_vector3	t = (t_vector3){((double)w) / 2, ((double)h) / 2, 0};
	t_point			p;
	char			*line;
	char			**col;

	line = get_next_line(fd);
	p = (t_point){0, 0, 0};
	while (line)
	{
		col = ft_split(line, ' ');
		p.x = 0;
		while (col[p.x] && *col[p.x] != '\n')
		{
			ob->dots[w * p.y + p.x] = (t_vector3){
				(p.x + 0.5) - t.x, (p.y + 0.5) - t.y, ft_atoi(col[p.x])};
			if (p.x < w - 1)
				ob->lines[p.c++] = (t_line){w * p.y + p.x, w * p.y + (p.x + 1)};
			if (p.y < h - 1)
				ob->lines[p.c++] = (t_line){w * p.y + p.x, w * (p.y + 1) + p.x};
			free(col[p.x++]);
		}
		free(line);
		line = get_next_line(fd);
		p.y++;
	}
}

t_obj	*create_map(const char *path)
{
	const int	fd = open(path, O_RDONLY);
	const int	height = get_height(path);
	const int	width = get_width(path);
	const int	line_cnt = (width - 1) * height + (height - 1) * width;
	t_obj		*res;

	if (width < 1 || height < 0)
		err_exit(ERR_PARAM);
	res = ft_calloc_guard(sizeof(t_obj));
	res->dots = ft_calloc_guard(sizeof(t_vector3) * width * height);
	res->d = ft_calloc_guard(sizeof(t_vector3) * width * height);
	res->dot_len = width * height;
	res->lines = ft_calloc_guard(sizeof(t_vector3) * line_cnt);
	res->line_len = line_cnt;
	res->scl = vect3(1, 1, 1);
	parse(res, fd, width, height);
	return (res);
}
