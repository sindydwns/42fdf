/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m3_mul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:07:23 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/26 21:03:51 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_matrix3	m3_mul(t_matrix3 m1, double d)
{
	return ((t_matrix3){
		vmul3(m1.v1, d),
		vmul3(m1.v2, d),
		vmul3(m1.v3, d),
	});
}
