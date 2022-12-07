/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:20:59 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/08 03:26:00 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define KEY_ESC 53
# include <stdlib.h>
# include "mlx.h"
# include "draw.h"
#include			<stdio.h>

typedef struct s_map
{
	int	*map;
	int	width;
	int height;
}	t_map;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_camera
{
	t_vector	pos;
	t_vector	dir;
	t_vector	rot;
	int			zoom;
}	t_camera;

typedef struct s_extra
{
	t_point	mouse;
}	t_extra;

typedef struct s_data
{
	void				*mlx;
	void				*win;
	unsigned long long	frame;
	t_img				img;
	t_map				map;
	t_camera			camera;
	t_extra				extra;
}	t_data;

int		init_map(t_map *map, int width, int height);
void	destroy_map(t_map *map);
int		mapv(t_map *map, int x, int y);

#endif
