/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_unit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:07:23 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/27 20:46:31 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_matrix4	m4_unit(void)
{
	return ((t_matrix4){
		(t_vector4){1, 0, 0, 0},
		(t_vector4){0, 1, 0, 0},
		(t_vector4){0, 0, 1, 0},
		(t_vector4){0, 0, 0, 1}
	});
}
