/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:07:57 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/07 15:14:11 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "draw.h"

static double	distance(t_point a, t_point b)
{
	const double	dx = b.x - a.x;
	const double	dy = b.y - a.y;

	return (sqrt(dx * dx + dy * dy));
}

int	draw_circle(t_img *target, t_point center, int radius, int color)
{
	t_point	curr;
	t_point	end;
	int		x;

	curr.x = center.x - radius;
	curr.y = center.y - radius;
	end.x = center.x + radius;
	end.y = center.y + radius;
	while (curr.y != end.y)
	{
		x = curr.x;
		while (x != end.x)
		{
			if (distance(center, (t_point){x, curr.y}) < radius)
				draw_pixel(target, (t_point){x, curr.y}, color);
			x++;
		}
		curr.y++;
	}
	return (0);
}
