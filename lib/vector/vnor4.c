/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vnor4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:09:26 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/18 13:22:00 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector4	vnor4(t_vector4 v1)
{
	const double	mag = vmag4(v1);

	if (mag == 0)
		return ((t_vector4){0, 0, 0, 0});
	return (vmul4(v1, 1 / mag));
}