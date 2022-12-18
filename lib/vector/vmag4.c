/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmag4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:09:26 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/18 13:21:20 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

double	vmag4(t_vector4 v1)
{
	return (sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z + v1.w * v1.w));
}
