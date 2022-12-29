/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyset_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 23:55:15 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/30 01:48:42 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	map_transform(t_obj *map, int *key)
{
	map->pos = (t_vector3){\
		map->pos.x + key[KEY_D] - key[KEY_A], \
		map->pos.y + key[KEY_W] - key[KEY_S], \
		map->pos.z + key[KEY_R] - key[KEY_F]};
	map->scl = (t_vector3){\
		map->scl.x, \
		map->scl.y, \
		map->scl.z * (1 + (key[KEY_T] - key[KEY_G]) * 0.05)};
	map->rot = (t_vector3){\
		map->rot.x + key[KEY_RIGHT] - key[KEY_LEFT], \
		map->rot.y + key[KEY_UP] - key[KEY_DOWN], \
		map->rot.z + key[KEY_E] - key[KEY_Q]};
}

static void	cam_transform(t_camera *cam, int *key)
{
	cam->pos = (t_vector3){\
		cam->pos.x + key[KEY_D] - key[KEY_A], \
		cam->pos.y + key[KEY_W] - key[KEY_S], \
		cam->pos.z + key[KEY_R] - key[KEY_F]};
	cam->zoom = cam->zoom * (1 + (key[KEY_PLUS] - key[KEY_MINUS]) * 0.05);
	cam->rot = (t_vector3){\
		cam->rot.x + key[KEY_RIGHT] - key[KEY_LEFT], \
		cam->rot.y + key[KEY_UP] - key[KEY_DOWN], \
		cam->rot.z + key[KEY_E] - key[KEY_Q]};
}

static void	preset(t_camera *cam, t_obj *map, int *key)
{
	if (key[KEY_1])
	{
		cam->pos = (t_vector3){-100, 100, 100};
		cam->rot = (t_vector3){-45, -atan(1 / sqrt(2)) * 180 / M_PI, 30};
	}
	if (key[KEY_2])
	{
		cam->pos = (t_vector3){100, 100, 100};
		cam->rot = (t_vector3){-45, atan(1 / sqrt(2)) * 180 / M_PI, -30};
	}
	if (key[KEY_QUESTION])
	{
		cam->rot = (t_vector3){0, 0, 0};
		cam->pos = (t_vector3){0, 0, 0};
		map->rot = (t_vector3){0, 0, 0};
		map->pos = (t_vector3){0, 0, 0};
	}
}

static void	special(t_camera *cam, int *key)
{
	if (key[KEY_DOT])
	{
		cam->pos.x -= -(cam->pos.x < 0) + (cam->pos.x > 0);
		cam->pos.y -= -(cam->pos.y < 0) + (cam->pos.y > 0);
		cam->pos.z -= -(cam->pos.z < 0) + (cam->pos.z > 0);
	}
	if (key[KEY_COMMA])
	{
		cam->pos.x += -(cam->pos.x < 0) + (cam->pos.x > 0);
		cam->pos.y += -(cam->pos.y < 0) + (cam->pos.y > 0);
		cam->pos.z += -(cam->pos.z < 0) + (cam->pos.z > 0);
	}
}

void	keystrock(t_data *data)
{
	if (data->ex.key[KEY_SHIFT])
		map_transform(data->map, data->ex.key);
	else
		cam_transform(&data->camera, data->ex.key);
	preset(&data->camera, data->map, data->ex.key);
	special(&data->camera, data->ex.key);
}
