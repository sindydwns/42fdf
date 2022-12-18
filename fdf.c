/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:48:53 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/18 20:30:43 by yonshin          ###   ########.fr       */
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

t_matrix4	get_move_matrix(t_vector3 v)
{
	return ((t_matrix4){
		(t_vector4){1, 0, 0, 0},
		(t_vector4){0, 1, 0, 0},
		(t_vector4){0, 0, 1, 0},
		(t_vector4){v.x, v.y, v.z, 1}
	});
}

t_matrix4	get_rotate_matrix(t_vector3 v)
{
	const double	degree = M_PI / 180;
	const double	sx = sin(v.x * degree);
	const double	sy = sin(v.y * degree);
	const double	sz = sin(v.z * degree);
	const double	cx = cos(v.x * degree);
	const double	cy = cos(v.y * degree);
	const double	cz = cos(v.z * degree);
	const t_matrix3	rx = (t_matrix3){
		vect3(cx, 0, -sx),
		vect3(0, 1, 0),
		vect3(sx, 0, cx)
	};
	const t_matrix3	ry = (t_matrix3){
		vect3(1, 0, 0),
		vect3(0, cy, sy),
		vect3(0, -sy, cy)
	};
	const t_matrix3	rz = (t_matrix3){
		vect3(cz, sz, 0),
		vect3(-sz, cz, 0),
		vect3(0, 0, 1)
	};
	const t_matrix3 rot = m3_mul_m3(rx, m3_mul_m3(ry, rz));

	return ((t_matrix4){
		(t_vector4){rot.v1.x, rot.v1.y, rot.v1.z, 0},
		(t_vector4){rot.v2.x, rot.v2.y, rot.v2.z, 0},
		(t_vector4){rot.v3.x, rot.v3.y, rot.v3.z, 0},
		(t_vector4){0, 0, 0, 1},
	});
}

void	render_frame(t_img *img, t_map *map, t_camera *camera, t_extra *e)
{
	// double a = camera->rot.x;
	// double b = camera->rot.y;
	// double r = camera->rot.z;
	// t_vector local_x = vect3(cos(a) * cos(r) + sin(a) * sin(b) * sin(r), cos(b) * sin(r), -sin(a) * cos(r) + cos(a) * sin(b) * sin(r));
	// t_vector local_y = vect3(-cos(a) * sin(r) + sin(a) * sin(b) * cos(r), cos(b) * cos(r), sin(a) * sin(r) + cos(a) * sin(b) * cos(r));
	// t_vector local_z = vect3(sin(a) * cos(b), -sin(b), cos(a) * cos(b));
	// printf("%.2f %.2f\n", camera->pos.x, camera->pos.y);
	camera->pos.z = -1000;
	camera->rot.x += 1;
	t_matrix4 move = get_move_matrix(vrev3(camera->pos));
	t_matrix4 rotate = get_rotate_matrix(vrev3(camera->rot));
	t_matrix4 xxx = m4_mul_m4(rotate, move);
	t_vector3 *new_map = malloc(sizeof(t_vector3) * map->height * map->width);
	for (int y = 0; y < map->height; y++) {
		for (int x = 0; x < map->width; x++) {
			t_vector3 *point = new_map + (y * map->width + x);
			*point = vmul3(vect3(x, y, map->map[map->width * y + x]), camera->zoom);
			t_vector4 res = m4_mul_v4(xxx, vect4(point->x, point->y, point->z, 1));
			*point = vect3(res.x, res.y, res.z);
		}
		printf("\n");
	}
	for (int y = 0; y < map->height; y++) {
		for (int x = 0; x < map->width; x++) {
			t_vector3 *point = new_map + (y * map->width + x);
			t_point a = (t_point){point->x + WIDTH / 2, point->y + HEIGHT / 2};
			printf("[%3d %3d %3d] ", (int)point->x, (int)point->y, (int)point->z);
			if (point->z < 0)
				continue;
			if (x < map->width - 1)
			{
				point = new_map + (y * map->width + x + 1);
				t_point b = (t_point){point->x + WIDTH / 2, point->y + HEIGHT / 2};
				draw_line(img, a, b, C_YELLOW);
			}
			if (y < map->height - 1)
			{
				point = new_map + ((y + 1) * map->width + x);
				t_point b = (t_point){point->x + WIDTH / 2, point->y + HEIGHT / 2};
				draw_line(img, a, b, C_YELLOW);
			}
			draw_pixel(img, a, C_WHITE);
		}
		printf("\n");
	}
	printf("\n");
	free(new_map);
	e++	;
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
		data->camera.pos.y -= 15;
	else if (key_code == KEY_A)
		data->camera.pos.x -= 15;
	else if (key_code == KEY_S)
		data->camera.pos.y += 15;
	else if (key_code == KEY_D)
		data->camera.pos.x += 15;
	else if (key_code == KEY_R)
		data->camera.pos.z += 15;
	else if (key_code == KEY_F)
		data->camera.pos.z -= 15;
	else if (key_code == KEY_Q)
		data->camera.rot.x += 15;
	else if (key_code == KEY_E)
		data->camera.rot.x -= 15;
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
	data.camera.zoom = 3;
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "fdf");
	data.img.size = (t_point){WIDTH, HEIGHT};
	data.img.obj = mlx_new_image(data.mlx, data.img.size.x, data.img.size.y);
	data.img.addr = mlx_get_data_addr(data.img.obj, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	mlx_put_image_to_window(data.mlx, data.win, data.img.obj, 0, 0);
	mlx_key_hook(data.win, (int (*)(void *))key_down_events, &data);
	mlx_loop_hook(data.mlx, (int (*)(void *))render_next_frame, &data);
	mlx_loop(data.mlx);
}
