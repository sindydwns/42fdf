/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:48:53 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/01 01:06:37 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"

int	update(t_data *data)
{
	draw_line(&data->img, (t_point){10, 10}, (t_point){10, 100}, 0xFFFF00);
	data->frame++;
	return (1);
}

#include <unistd.h>
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cursor;

	cursor = (unsigned char *)b;
	while (len-- > 0)
		cursor[len] = (unsigned char)c;
	return (b);
}

#include <math.h>
static double	distance(t_point a, t_point b)
{
	const double dx = b.x - a.x;
	const double dy = b.y - a.y;
	return sqrt(dx * dx + dy * dy);
}

int	render_next_frame(t_data *data)
{
	t_point	mouse;

	mlx_mouse_get_pos(data->win, &mouse.x, &mouse.y);
	ft_memset(data->img.addr, 0, WIDTH * HEIGHT * data->img.bits_per_pixel / 8);
	// draw_rect(&data->img, (t_point){WIDTH / 2, HEIGHT / 2}, mouse, C_WHITE);
	// draw_line(&data->img, (t_point){WIDTH / 2, HEIGHT / 2}, mouse, C_RED);
	draw_circle(&data->img, (t_point){WIDTH / 2, HEIGHT / 2}, distance((t_point){WIDTH / 2, HEIGHT / 2}, mouse), C_YELLOW);
	mlx_put_image_to_window(data->mlx, data->win, data->img.obj, 0, 0);
	return (0);
}

int	main(void)
{
	t_data	data;
	// void	*mlx_win;

	data.mlx = mlx_init();
	data.frame = 0;
	if (data.mlx == 0)
		return (1);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "fdf");
	data.img.obj = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.obj, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);

	// draw_line(&data.img, (t_point){100, 100}, (t_point){50, 0}, C_GREEN);
	// draw_line(&data.img, (t_point){0, 100}, (t_point){100, 0}, C_YELLOW);
	// draw_line(&data.img, (t_point){0, 100}, (t_point){63, 0}, C_YELLOW);
	// draw_line(&data.img, (t_point){0, 100}, (t_point){50, 0}, C_YELLOW);
	// draw_line(&data.img, (t_point){100, 100}, (t_point){200, 200}, C_RED);
	// draw_line(&data.img, (t_point){100, 100}, (t_point){100, 200}, 0x0000FF);
	// draw_line(&data.img, (t_point){100, 100}, (t_point){200, 100}, 0xFFFF00);
	// draw_line(&data.img, (t_point){100, 100}, (t_point){50, 200}, 0x00FFFF);
	// draw_line(&data.img, (t_point){100, 100}, (t_point){200, 50}, 0xFF00FF);
	// draw_line(&data.img, (t_point){100, 100}, (t_point){200, 175}, 0xFFFFFF);
	draw_rect(&data.img, (t_point){100, 100}, (t_point){0, 200}, C_YELLOW);

	mlx_put_image_to_window(data.mlx, data.win, data.img.obj, 0, 0);
	// draw_line(&data, (t_point){0, 0}, (t_point){100, 100}, 0xFFFFFF);
	mlx_loop_hook(data.mlx, (int (*)(void *))render_next_frame, &data);
	mlx_loop(data.mlx);
	// mlx_loop(mlx);
}
