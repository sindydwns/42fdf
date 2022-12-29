/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_sphere_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:30:13 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/30 07:23:04 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf_bonus.h"

static int	get_height(const char *path)
{
	const int	fd = open(path, O_RDONLY);
	char		*line;
	int			height;

	if (fd < 0)
		err_exit(ERR_PARAM);
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
		err_exit(ERR_PARAM);
	width = 0;
	line = get_next_line(fd);
	if (line == 0)
		err_exit(ERR_PARAM);
	col = ft_split(line, ' ');
	if (col == 0)
		err_exit(ERR_PARAM);
	while (col[width] && (*col[width] == '-' || ft_isdigit(*col[width])))
		free(col[width++]);
	free(col);
	free(line);
	close(fd);
	return (width);
}

static t_point	place_sphere(t_obj *ob, char *num, t_point s, t_point p)
{
	t_vector3	v;

	v.x = cos(2 * M_PI / s.x * (p.x + 0.5)) * sin(M_PI / s.y * (p.y + 0.5));
	v.y = sin(2 * M_PI / s.x * (p.x + 0.5)) * sin(M_PI / s.y * (p.y + 0.5));
	v.z = cos(M_PI / s.y * (p.y + 0.5));
	ob->dots[s.x * p.y + p.x] = vmul3(v, 1 + 0.01 * ft_atoi(num));
	if (p.x < s.x - 1)
		ob->lines[p.c++] = (t_line){s.x * p.y + p.x, s.x * p.y + (p.x + 1)};
	else
		ob->lines[p.c++] = (t_line){s.x * p.y + p.x, s.x * p.y};
	if (p.y < s.y - 1)
		ob->lines[p.c++] = (t_line){s.x * p.y + p.x, s.x * (p.y + 1) + p.x};
	return (p);
}

static void	parse(t_obj *ob, int fd, t_point s)
{
	t_point		p;
	char		*line;
	char		**col;

	line = get_next_line(fd);
	p = (t_point){0, 0, 0};
	while (line)
	{
		col = ft_split(line, ' ');
		p.x = 0;
		while (col[p.x] && *col[p.x] != '\n')
		{
			p = place_sphere(ob, col[p.x], s, p);
			free(col[p.x++]);
		}
		free(line);
		line = get_next_line(fd);
		p.y++;
	}
}

t_obj	*create_sphere(const char *path)
{
	const int	fd = open(path, O_RDONLY);
	const int	height = get_height(path);
	const int	width = get_width(path);
	const int	line_cnt = width * height * 2;
	t_obj		*res;

	if (width < 1 || height < 1)
		err_exit(ERR_PARAM);
	res = ft_calloc_guard(sizeof(t_obj));
	res->dots = ft_calloc_guard(sizeof(t_vector3) * width * height);
	res->d = ft_calloc_guard(sizeof(t_vector3) * width * height);
	res->dot_len = width * height;
	res->lines = ft_calloc_guard(sizeof(t_vector3) * line_cnt);
	res->line_len = line_cnt;
	res->scl = vect3(100, 100, 100);
	parse(res, fd, (t_point){width, height, 0});
	return (res);
}
