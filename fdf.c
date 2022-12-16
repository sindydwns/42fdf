/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:48:53 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/17 03:52:09 by yonshin          ###   ########.fr       */
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
	camera++;
	draw_line(img, (t_point){WIDTH / 2, HEIGHT / 2}, e->mouse, C_YELLOW);
	camera->pos = vect(50, 50, 50);
	camera->rot = vect(45, 35.26438968, 45);
	for (int x = 0; x < map->width; x++) {
		for (int y = 0; y < map->height; y++) {
			t_vector point = vmul(vect(x, y, map->map[map->width * y + x]), 10);
			double a = camera->rot.x;
			double b = camera->rot.y;
			double r = camera->rot.z;
			cos(a) * cos(r) + sin(a) * sin(b) * sin(r)
			// t_vector normal = vmul(dir, vdot(dir, point));
			// t_vector result = vsub(point, normal);
			// t_vector center = vsub(result, camera->pos);
		}
	}
	e++;
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

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		exit(1);
	ft_memset(&data, 0, sizeof(data));
	data.mlx = mlx_init();
	if (data.mlx == 0 || parse_map(argv[1], &data.map))
		exit(1);
	data.camera.zoom = 10;
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "fdf");
	data.img.size = (t_point){WIDTH, HEIGHT};
	data.img.obj = mlx_new_image(data.mlx, data.img.size.x, data.img.size.y);
	data.img.addr = mlx_get_data_addr(data.img.obj, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	mlx_put_image_to_window(data.mlx, data.win, data.img.obj, 0, 0);
	mlx_key_hook(data.win, (int (*)(void *))key_down_events, &data);
	mlx_loop_hook(data.mlx, (int (*)(void *))render_next_frame, &data);
	mlx_loop(data.mlx);
}
