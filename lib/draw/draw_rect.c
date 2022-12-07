/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:06:28 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/07 15:11:56 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	draw_rect(t_img *target, t_point start, t_point end, int color)
{
	t_point	curr;
	int		x;

	curr.x = start.x * (start.x < end.x) + end.x * (start.x >= end.x);
	curr.y = start.y * (start.y < end.y) + end.y * (start.y >= end.y);
	end.x = start.x * (start.x > end.x) + end.x * (start.x <= end.x);
	end.y = start.y * (start.y > end.y) + end.y * (start.y <= end.y);
	while (curr.y != end.y)
	{
		x = curr.x;
		while (x != end.x)
			draw_pixel(target, (t_point){x++, curr.y}, color);
		draw_pixel(target, (t_point){x, curr.y}, color);
		curr.y++;
	}
	while (curr.x != end.x)
		draw_pixel(target, (t_point){curr.x++, curr.y}, color);
	return (0);
}
