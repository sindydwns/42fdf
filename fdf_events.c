/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 23:41:46 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/30 00:55:00 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_event(void)
{
	exit(0);
	return (0);
}

int	keydown_event(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_event();
	if (keycode >= 0 && keycode < MAX_KEYCODE)
		data->ex.key[keycode] = 1;
	return (0);
}

int	keyup_event(int keycode, t_data *data)
{
	if (keycode >= 0 && keycode < MAX_KEYCODE)
		data->ex.key[keycode] = 0;
	return (0);
}

int	mouse_event(int button, int x, int y, t_data *param)
{
	x++;
	y++;
	if (button == MOUSE_WHEEL_UP && param->camera.zoom < 100)
		param->camera.zoom *= 1.2;
	if (button == MOUSE_WHEEL_DOWN && param->camera.zoom > 0.1)
		param->camera.zoom /= 1.2;
	if (param->camera.zoom < 0.1)
		param->camera.zoom = 0.1;
	return (0);
}
