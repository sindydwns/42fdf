/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m3_mul_v3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:48:38 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/18 13:16:54 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector3	m3_mul_v3(t_matrix3 m1, t_vector3 v1)
{
	const t_vector3	res1 = vmul3(m1.v1, v1.x);
	const t_vector3	res2 = vmul3(m1.v2, v1.y);
	const t_vector3	res3 = vmul3(m1.v3, v1.z);

	return (vsum3(vsum3(res1, res2), res3));
}
