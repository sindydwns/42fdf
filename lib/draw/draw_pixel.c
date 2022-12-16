/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:46:00 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/17 03:42:19 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	draw_pixel(t_img *t, t_point p, int c)
{
	char		*dst;

	if (p.x < 0 || p.x >= t->size.x)
		return (1);
	if (p.y < 0 || p.y >= t->size.y)
		return (1);
	dst = t->addr + (p.y * t->line_length + p.x * (t->bits_per_pixel / 8));
	*(unsigned int *)dst = c;
	return (0);
}
