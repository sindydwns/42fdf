/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:46:00 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/29 17:57:39 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	draw_pixel(t_img *t, t_point p, int c)
{
	char		*dst;

	dst = t->addr + (p.y * t->line_length + p.x * (t->bits_per_pixel / 8));
	*(unsigned int*)dst = c;
	return (0);
}
