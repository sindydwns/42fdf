/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:46:33 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/30 00:36:48 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static int	abs(int v)
{
	if (v < 0)
		return (-v);
	return (v);
}

static int	draw_line_low(t_img *target, t_point start, t_point end, int color)
{
	int	dx;
	int	dy;
	int	yi;
	int	d;
	int	y;
	int	x;

	dx = end.x - start.x;
	dy = end.y - start.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = (2 * dy) - dx;
	y = start.y;
	x = start.x;
	while (x <= end.x)
	{
		draw_pixel(target, (t_point){x, y}, color);
		if (d > 0)
		{
			y = y + yi;
			d = d + (2 * (dy - dx));
		}
		else
			d = d + 2 * dy;
		x++;
	}
	return (0);
}

static int	draw_line_high(t_img *target, t_point start, t_point end, int color)
{
	int	dx;
	int	dy;
	int	xi;
	int	d;
	int	y;
	int	x;

	dx = end.x - start.x;
	dy = end.y - start.y;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = (2 * dx) - dy;
	x = start.x;
	y = start.y;
	while (y <= end.y)
	{
		draw_pixel(target, (t_point){x, y}, color);
		if (d > 0)
		{
			x = x + xi;
			d = d + (2  * (dx - dy));
		}
		else
			d = d + 2 * dy;
		y++;
	}
	return (0);
}

int	draw_line(t_img *target, t_point start, t_point end, int color)
{
	if (abs(end.x - start.x) > abs(end.y - start.y))
	{
		if (start.x < end.x)
			return draw_line_low(target, start, end, color);
		else
			return draw_line_low(target, end, start, color);
	}
	else
	{
		if (start.y < end.y)
			return draw_line_high(target, start, end, color);
		else
			return draw_line_high(target, end, start, color);
	}
}
