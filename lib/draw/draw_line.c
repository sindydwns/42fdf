/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:46:33 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/27 23:52:16 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "draw.h"

static int	abs(int value)
{
	return (value * ((value > 0) - (value < 0)));
}

static void	draw_line_row(t_img *target, t_point start, t_point end)
{
	const int	dx = end.x - start.x;
	const int	dy = end.y - start.y;
	int			d;

	d = (2 * abs(dy)) - dx;
	while (start.x < end.x)
	{
		draw_pixel(target, start);
		if (d > 0)
		{
			start.y += (dy > 0) - (dy < 0);
			d += 2 * (abs(dy) - dx);
		}
		else
			d += 2 * abs(dy);
		start.x++;
	}
	draw_pixel(target, end);
}

static void	draw_line_high(t_img *target, t_point start, t_point end)
{
	const int	dx = end.x - start.x;
	const int	dy = end.y - start.y;
	int			d;

	d = (2 * abs(dx)) - dy;
	while (start.y < end.y)
	{
		draw_pixel(target, start);
		if (d > 0)
		{
			start.x += (dx > 0) - (dx < 0);
			d += 2 * (abs(dx) - dy);
		}
		else
			d += 2 * abs(dx);
		start.y++;
	}
	draw_pixel(target, end);
}

static void	draw(t_img *target, t_point start, t_point end)
{
	if (abs(end.y - start.y) < abs(end.x - start.x))
	{
		if (start.x > end.x)
			draw_line_row(target, end, start);
		else
			draw_line_row(target, start, end);
	}
	else
	{
		if (start.y > end.y)
			draw_line_high(target, end, start);
		else
			draw_line_high(target, start, end);
	}
}

int	draw_line(t_img *target, t_point start, t_point end)
{
	const int	sc = (start.x < 0) << 3 | (start.x >= WIDTH) << 2 \
					| (start.y < 0) << 1 | (start.y >= HEIGHT);
	const int	ec = (end.x < 0) << 3 | (end.x >= WIDTH) << 2 \
					| (end.y < 0) << 1 | (end.y >= HEIGHT);

	if ((sc & ec) == 0)
		draw(target, start, end);
	return (0);
}
