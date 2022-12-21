/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:46:33 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/21 15:59:16 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "draw.h"

static int	abs(int value)
{
	return (value * ((value > 0) - (value < 0)));
}

int	draw_line(t_img *target, t_point start, t_point end)
{
	const int	dx = abs(end.x - start.x);
	const int	dy = -abs(end.y - start.y);
	int			error;

	error = dx + dy;
	while (start.x != end.x || start.y != end.y)
	{
		draw_pixel(target, start);
		if (error * 2 >= dy)
		{
			if (start.x == end.x)
				break ;
			error += dy;
			start.x += (start.x < end.x) - (start.x >= end.x);
		}
		if (error * 2 <= dx)
		{
			if (start.y == end.y)
				break ;
			error += dx;
			start.y += (start.y < end.y) - (start.y >= end.y);
		}
	}
	return (0);
}
