/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:46:33 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/29 18:01:10 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	draw_line(t_img *target, t_point start, t_point end, int color)
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
