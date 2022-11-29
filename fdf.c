/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:48:53 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/30 00:45:31 by yonshin          ###   ########.fr       */
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

	// for (int i = 0; i < 0xFF; i++)
	// {
	// 	draw_pixel(&data.img, (t_point){i, i}, 0xFFFFFFFF);
	// 	draw_pixel(&data.img, (t_point){0xFF - i, i}, 0xFFFFFFFF);
	// }

	draw_line(&data.img, (t_point){100, 100}, (t_point){50, 0}, C_GREEN);
	draw_line(&data.img, (t_point){0, 100}, (t_point){100, 0}, C_YELLOW);
	draw_line(&data.img, (t_point){0, 100}, (t_point){63, 0}, C_YELLOW);
	draw_line(&data.img, (t_point){0, 100}, (t_point){50, 0}, C_YELLOW);
	draw_line(&data.img, (t_point){100, 100}, (t_point){200, 200}, C_RED);
	// draw_line(&data.img, (t_point){100, 100}, (t_point){100, 200}, 0x0000FF);
	// draw_line(&data.img, (t_point){100, 100}, (t_point){200, 100}, 0xFFFF00);
	// draw_line(&data.img, (t_point){100, 100}, (t_point){50, 200}, 0x00FFFF);
	// draw_line(&data.img, (t_point){100, 100}, (t_point){200, 50}, 0xFF00FF);
	// draw_line(&data.img, (t_point){100, 100}, (t_point){200, 175}, 0xFFFFFF);

	mlx_put_image_to_window(data.mlx, data.win, data.img.obj, 0, 0);
	// draw_line(&data, (t_point){0, 0}, (t_point){100, 100}, 0xFFFFFF);
	mlx_loop(data.mlx);
	// mlx_loop_hook(data.mlx, (int (*)(void *))update, &data);
	// mlx_loop(mlx);
}
