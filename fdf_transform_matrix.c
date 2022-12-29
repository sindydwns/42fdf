/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transform_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 23:28:34 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/29 23:40:51 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix4	get_move_matrix(t_vector3 v)
{
	return ((t_matrix4){
		(t_vector4){1, 0, 0, 0},
		(t_vector4){0, 1, 0, 0},
		(t_vector4){0, 0, 1, 0},
		(t_vector4){v.x, v.y, v.z, 1}
	});
}

static t_matrix3	get_rotate_matrix_v3(t_vector3 v)
{
	const double	d = M_PI / 180;
	const t_vector3	s3 = (t_vector3){sin(v.x * d), sin(v.y * d), sin(v.z * d)};
	const t_vector3	c3 = (t_vector3){cos(v.x * d), cos(v.y * d), cos(v.z * d)};

	return (m3_mul_m3((t_matrix3){\
		vect3(1, 0, 0), \
		vect3(0, c3.x, s3.x), \
		vect3(0, -s3.x, c3.x) \
	}, m3_mul_m3((t_matrix3){\
		vect3(c3.y, 0, -s3.y), \
		vect3(0, 1, 0), \
		vect3(s3.y, 0, c3.y) \
	}, (t_matrix3){\
		vect3(c3.z, s3.z, 0), \
		vect3(-s3.z, c3.z, 0), \
		vect3(0, 0, 1) \
	})));
}

t_matrix4	get_rotate_matrix(t_vector3 v)
{
	const t_matrix3	rot = get_rotate_matrix_v3(v);

	return ((t_matrix4){
		(t_vector4){rot.v1.x, rot.v1.y, rot.v1.z, 0},
		(t_vector4){rot.v2.x, rot.v2.y, rot.v2.z, 0},
		(t_vector4){rot.v3.x, rot.v3.y, rot.v3.z, 0},
		(t_vector4){0, 0, 0, 1}
	});
}

t_matrix4	get_scale_matrix(t_vector3 v)
{
	return ((t_matrix4){
		(t_vector4){v.x, 0, 0, 0},
		(t_vector4){0, v.y, 0, 0},
		(t_vector4){0, 0, v.z, 0},
		(t_vector4){0, 0, 0, 1},
	});
}
