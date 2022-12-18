/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:20:59 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/18 14:26:08 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_R 15
# define KEY_F 3
# define KEY_Q 12
# define KEY_E 14
# include <stdlib.h>
# include "mlx.h"
# include "draw.h"
# include "vector.h"
# include "math.h"
#include			<stdio.h>

typedef struct s_map
{
	int	*map;
	int	width;
	int	height;
}	t_map;

typedef struct s_camera
{
	t_vector3	pos;
	t_vector3	rot;
	double		zoom;
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

int		parse_map(const char *path, t_map *map);
void	destroy_map(t_map *map);
int		mapv(t_map *map, int x, int y);

#endif
