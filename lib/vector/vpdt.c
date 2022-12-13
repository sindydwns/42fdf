/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vpdt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:52:22 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/08 08:17:54 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vpdt(t_vector v1, t_vector v2)
{
	const double	x = v1.y * v2.z - v1.z * v2.y;
	const double	y = v1.z * v2.x - v1.x * v2.z;
	const double	z = v1.x * v2.y - v1.y * v2.x;

	return ((t_vector){x, y, z});
}
