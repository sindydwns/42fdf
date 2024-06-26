/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmul4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:09:26 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/17 16:12:05 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector4	vmul4(t_vector4 v1, double v2)
{
	return ((t_vector4){v1.x * v2, v1.y * v2, v1.z * v2, v1.w * v2});
}
