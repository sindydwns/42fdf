/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m3_mul_m3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:48:38 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/18 18:26:26 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
| a11 a12 a13 | | b11 b12 b13 |
| a21 a22 a23 | | b21 b22 b23 |
| a31 a32 a33 | | b31 b32 b33 |
===============================
| r1c1 r1c2 r1c3 |
| r2c1 r2c2 r2c3 |
| r3c1 r3c2 r3c3 |
*/
t_matrix3	m3_mul_m3(t_matrix3 m1, t_matrix3 m2)
{
	const t_vector3	v1 = (t_vector3){
		vdot3((t_vector3){m1.v1.x, m1.v2.x, m1.v3.x}, m2.v1),
		vdot3((t_vector3){m1.v1.y, m1.v2.y, m1.v3.y}, m2.v1),
		vdot3((t_vector3){m1.v1.z, m1.v2.z, m1.v3.z}, m2.v1)
	};
	const t_vector3	v2 = (t_vector3){
		vdot3((t_vector3){m1.v1.x, m1.v2.x, m1.v3.x}, m2.v2),
		vdot3((t_vector3){m1.v1.y, m1.v2.y, m1.v3.y}, m2.v2),
		vdot3((t_vector3){m1.v1.z, m1.v2.z, m1.v3.z}, m2.v2)
	};
	const t_vector3	v3 = (t_vector3){
		vdot3((t_vector3){m1.v1.x, m1.v2.x, m1.v3.x}, m2.v3),
		vdot3((t_vector3){m1.v1.y, m1.v2.y, m1.v3.y}, m2.v3),
		vdot3((t_vector3){m1.v1.z, m1.v2.z, m1.v3.z}, m2.v3)
	};

	return ((t_matrix3){v1, v2, v3});
}
