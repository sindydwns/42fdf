/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:48:53 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/17 16:04:23 by yonshin          ###   ########.fr       */
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
	// double a = camera->rot.x;
	// double b = camera->rot.y;
	// double r = camera->rot.z;
	// t_vector local_x = vect3(cos(a) * cos(r) + sin(a) * sin(b) * sin(r), cos(b) * sin(r), -sin(a) * cos(r) + cos(a) * sin(b) * sin(r));
	// t_vector local_y = vect3(-cos(a) * sin(r) + sin(a) * sin(b) * cos(r), cos(b) * cos(r), sin(a) * sin(r) + cos(a) * sin(b) * cos(r));
	// t_vector local_z = vect3(sin(a) * cos(b), -sin(b), cos(a) * cos(b));
	printf("%.2f %.2f\n", camera->rot.x, camera->rot.y);
	for (int y = 0; y < map->height; y++) {
		for (int x = 0; x < map->width; x++) {
			t_vector3 point = vmul3(vect3(x, y, map->map[map->width * y + x]), camera->zoom);
			draw_pixel(img, (t_point){point.x, point.y}, C_YELLOW);
			// point = vect3(vdot3(point, local_x), vdot3(point, local_y), vdot3(point, local_z));
			
			printf("[%3d %3d] ", (int)point.x, (int)point.y);
		}
		printf("\n");
	}
	printf("\n");
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

void	key_down_events(int key_code, t_data *data)
{
	if (key_code == KEY_ESC)
		exit(0);
	else if (key_code == KEY_W)
		data->camera.rot.y += 15;
	else if (key_code == KEY_A)
		data->camera.rot.x -= 15;
	else if (key_code == KEY_S)
		data->camera.rot.y -= 15;
	else if (key_code == KEY_D)
		data->camera.rot.x += 15;
	printf("%.2f %.2f\n", data->camera.rot.x, data->camera.rot.y);
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
	data.camera.zoom = 25;
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "fdf");
	data.img.size = (t_point){WIDTH, HEIGHT};
	data.img.obj = mlx_new_image(data.mlx, data.img.size.x, data.img.size.y);
	data.img.addr = mlx_get_data_addr(data.img.obj, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	mlx_put_image_to_window(data.mlx, data.win, data.img.obj, 0, 0);
	mlx_key_hook(data.win, (int (*)(void *))key_down_events, &data);
	mlx_loop_hook(data.mlx, (int (*)(void *))render_next_frame, &data);
	mlx_loop(data.mlx);
}
