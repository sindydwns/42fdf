/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_mul_m4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:48:38 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/18 13:10:37 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

static double	one_value(t_vector4 v1, t_vector4 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w);
}

t_matrix4	m4_mul_m4(t_matrix4 m1, t_matrix4 m2)
{
	return ((t_matrix4){(t_vector4){
		one_value((t_vector4){m1.v1.x, m1.v2.x, m1.v3.x, m1.v4.x}, m2.v1),
		one_value((t_vector4){m1.v1.y, m1.v2.y, m1.v3.y, m1.v4.y}, m2.v1),
		one_value((t_vector4){m1.v1.z, m1.v2.z, m1.v3.z, m1.v4.z}, m2.v1),
		one_value((t_vector4){m1.v1.w, m1.v2.w, m1.v3.w, m1.v4.w}, m2.v1)
	}, (t_vector4){
		one_value((t_vector4){m1.v1.x, m1.v2.x, m1.v3.x, m1.v4.x}, m2.v2),
		one_value((t_vector4){m1.v1.y, m1.v2.y, m1.v3.y, m1.v4.y}, m2.v2),
		one_value((t_vector4){m1.v1.z, m1.v2.z, m1.v3.z, m1.v4.z}, m2.v2),
		one_value((t_vector4){m1.v1.w, m1.v2.w, m1.v3.w, m1.v4.w}, m2.v2)
	}, (t_vector4){
		one_value((t_vector4){m1.v1.x, m1.v2.x, m1.v3.x, m1.v4.x}, m2.v3),
		one_value((t_vector4){m1.v1.y, m1.v2.y, m1.v3.y, m1.v4.y}, m2.v3),
		one_value((t_vector4){m1.v1.z, m1.v2.z, m1.v3.z, m1.v4.z}, m2.v3),
		one_value((t_vector4){m1.v1.w, m1.v2.w, m1.v3.w, m1.v4.w}, m2.v3)
	}, (t_vector4){
		one_value((t_vector4){m1.v1.x, m1.v2.x, m1.v3.x, m1.v4.x}, m2.v4),
		one_value((t_vector4){m1.v1.y, m1.v2.y, m1.v3.y, m1.v4.y}, m2.v4),
		one_value((t_vector4){m1.v1.z, m1.v2.z, m1.v3.z, m1.v4.z}, m2.v4),
		one_value((t_vector4){m1.v1.w, m1.v2.w, m1.v3.w, m1.v4.w}, m2.v4)
	}});
}
