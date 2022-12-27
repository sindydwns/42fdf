/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m3_unit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:07:23 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/26 20:58:13 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_matrix3	m3_unit()
{
	return ((t_matrix3){
		(t_vector3){1, 0, 0},
		(t_vector3){0, 1, 0},
		(t_vector3){0, 0, 1}
	});
}