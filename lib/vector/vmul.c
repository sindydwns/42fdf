/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmul.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:52:17 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/08 08:05:08 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vmul(t_vector v1, double v2)
{
	return ((t_vector){v1.x * v2, v1.y * v2, v1.z * v2});
}
