/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_mul_v4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:48:38 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/18 13:19:50 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector4	m4_mul_v4(t_matrix4 m1, t_vector4 v1)
{
	const t_vector4	res1 = vmul4(m1.v1, v1.x);
	const t_vector4	res2 = vmul4(m1.v2, v1.y);
	const t_vector4	res3 = vmul4(m1.v3, v1.z);
	const t_vector4	res4 = vmul4(m1.v4, v1.w);

	return (vsub4(vsum4(vsum4(res1, res2), res3), res4));
}
