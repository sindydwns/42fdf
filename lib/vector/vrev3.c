/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vrev3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:31:18 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/17 17:31:19 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector3	vrev3(t_vector3 v1)
{
	return ((t_vector3){-v1.x, -v1.y, -v1.z});
}
