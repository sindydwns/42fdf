/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:28:06 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/08 08:29:55 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

double	vmag(t_vector v1)
{
	return sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
}
