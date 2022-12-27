/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:46:33 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/27 17:19:29 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "draw.h"

static int	abs(int value)
{
	return (value * ((value > 0) - (value < 0)));
}

static void	draw(t_img *target, t_point start, t_point end)
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
}

int	draw_line(t_img *target, t_point start, t_point end)
{
	const int	sc = (start.x < 0) << 3 | (start.x >= WIDTH) << 2 | (start.y < 0) << 1 | (start.y >= HEIGHT);
	const int	ec = (end.x < 0) << 3 | (end.x >= WIDTH) << 2 | (end.y < 0) << 1 | (end.y >= HEIGHT);
	
	if ((sc & ec) == 0)
		draw(target, start, end);
	return (0);
}
