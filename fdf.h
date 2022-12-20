/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:20:59 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/20 20:15:53 by yonshin          ###   ########.fr       */
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
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define DEFER 0.85
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

typedef struct s_obj
{
	t_vector3	pos;
	t_vector3	rot;
	t_vector3	scl;
}	t_obj;

typedef struct s_camera
{
	t_vector3	pos;
	t_vector3	rot;
	t_vector3	trot;
	double		zoom;
	double		tzoom;
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
