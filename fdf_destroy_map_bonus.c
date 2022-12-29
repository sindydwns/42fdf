/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_destroy_map_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:30:41 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/30 01:48:33 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	destroy_map(t_obj *map)
{
	free(map->d);
	free(map->dots);
	free(map->lines);
	free(map);
}
