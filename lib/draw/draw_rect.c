/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:06:28 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/29 17:58:12 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	draw_rect(t_img *target, t_point start, t_point end, int color)
{
	target++;
	start.x++;
	end.x++;
	color++;
	return (0);
}
