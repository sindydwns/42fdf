/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_trans.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:07:23 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/26 20:57:15 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// transposed matrix
t_matrix4	m4_trans(t_matrix4 m1)
{
	return ((t_matrix4){
		(t_vector4){m1.v1.x, m1.v2.x, m1.v3.x, m1.v4.x},
		(t_vector4){m1.v1.y, m1.v2.y, m1.v3.y, m1.v4.y},
		(t_vector4){m1.v1.z, m1.v2.z, m1.v3.z, m1.v4.z},
		(t_vector4){m1.v1.w, m1.v2.w, m1.v3.w, m1.v4.w}
	});
}
