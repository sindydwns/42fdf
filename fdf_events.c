/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 23:41:46 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/30 02:13:59 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_event(void)
{
	exit(0);
	return (0);
}

int	keydown_event(int keycode)
{
	if (keycode == KEY_ESC)
		close_event();
	return (0);
}
