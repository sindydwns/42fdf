/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:48:53 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/08 03:36:05 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <unistd.h>
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cursor;

	cursor = (unsigned char *)b;
	while (len-- > 0)
		cursor[len] = (unsigned char)c;
	return (b);
}

void	render_frame(t_img *img, t_map *map, t_camera *camera, t_extra *e)
{
	map->width = map->height;
	camera->pos = (t_vector){1, 1, 1};
	for (int x = 0; x < map->width; x++) {
		for (int y = 0; y < map->height; y++) {
			t_vector p = (t_vector){x * 10, y * 10, 0};
			t_vector c = (t_vector){-1, -1, -1};
			t_vector f = (t_vector){p.x - c.x, p.y - c.y, p.z - c.z};
			
		}
	}
	draw_line(img, (t_point){100, 100}, e->mouse, C_YELLOW);
}

int	render_next_frame(t_data *data)
{
	data->frame++;
	mlx_mouse_get_pos(data->win, &data->extra.mouse.x, &data->extra.mouse.y);
	ft_memset(data->img.addr, 0, WIDTH * HEIGHT * data->img.bits_per_pixel / 8);
	render_frame(&data->img, &data->map, &data->camera, &data->extra);
	mlx_put_image_to_window(data->mlx, data->win, data->img.obj, 0, 0);
	return (0);
}

void	key_down_events(int key_code)
{
	if (key_code == KEY_ESC)
		exit(0);
}

int	main(void)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(data));
	data.mlx = mlx_init();
	data.frame = 0;
	if (data.mlx == 0)
		return (1);
	if (init_map(&data.map, 10, 10))
		exit(1);
	data.camera.zoom = 10;
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "fdf");
	data.img.obj = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.obj, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	mlx_put_image_to_window(data.mlx, data.win, data.img.obj, 0, 0);
	mlx_key_hook(data.win, (int (*)(void *))key_down_events, &data);
	mlx_loop_hook(data.mlx, (int (*)(void *))render_next_frame, &data);
	mlx_loop(data.mlx);
}
