/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:25:23 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/08 01:53:09 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mapv(t_map *map, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	if (x >= map->width || y >= map->height)
		return (0);
	return (map->map[y * map->height + x]);
}
