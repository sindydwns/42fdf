/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:48:53 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/22 02:22:32 by yonshin          ###   ########.fr       */
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
	const double	d = M_PI / 180;
	const t_vector3	s3 = (t_vector3){sin(v.x * d), sin(v.y * d), sin(v.z * d)};
	const t_vector3	c3 = (t_vector3){cos(v.x * d), cos(v.y * d), cos(v.z * d)};
	const t_matrix3	rx = (t_matrix3){
		vect3(1, 0, 0),
		vect3(0, c3.x, s3.x),
		vect3(0, -s3.x, c3.x)
	};
	const t_matrix3	ry = (t_matrix3){
		vect3(c3.y, 0, -s3.y),
		vect3(0, 1, 0),
		vect3(s3.y, 0, c3.y)
	};
	const t_matrix3	rz = (t_matrix3){
		vect3(c3.z, s3.z, 0),
		vect3(-s3.z, c3.z, 0),
		vect3(0, 0, 1)
	};
	const t_matrix3 rot = m3_mul_m3(rx, m3_mul_m3(ry, rz));
	// const t_matrix3 rot = m3_mul_m3(rx, m3_mul_m3(rz, ry));
	// const t_matrix3 rot = m3_mul_m3(ry, m3_mul_m3(rz, rx));
	// const t_matrix3 rot = m3_mul_m3(ry, m3_mul_m3(rx, rz));
	// const t_matrix3 rot = m3_mul_m3(rz, m3_mul_m3(rx, ry));
	// const t_matrix3 rot = m3_mul_m3(rz, m3_mul_m3(ry, rx));

	return ((t_matrix4){
		(t_vector4){rot.v1.x, rot.v1.y, rot.v1.z, 0},
		(t_vector4){rot.v2.x, rot.v2.y, rot.v2.z, 0},
		(t_vector4){rot.v3.x, rot.v3.y, rot.v3.z, 0},
		(t_vector4){0, 0, 0, 1},
	});
}

int	render_frame(t_img *img, t_obj *map, t_camera *cam, t_extra *e)
{
	// cam->tzoom = cam->zoom;
	// cam->trot = cam->rot;
	cam->tzoom = cam->tzoom * DEFER + cam->zoom * (1 - DEFER);
	cam->trot = vsum3(vmul3(cam->trot, DEFER), vmul3(cam->rot, 1 - DEFER));
	t_matrix4 move = get_move_matrix(vrev3(cam->pos));
	t_matrix4 rotate = get_rotate_matrix(vrev3(cam->trot));
	// t_matrix4 xxx = m4_mul_m4(rotate, move);
	t_matrix4 xxx = m4_mul_m4(move, rotate);

	for (int i = 0; i < map->dot_len; i++) {
		t_vector3 point = map->dots[i];
		t_vector4 res = m4_mul_v4(xxx, vect4(point.x, point.y, point.z, 1));
		map->d[i] = vect3(-res.x, res.y, res.z);
	}

	for (int i = 0; i < map->line_len; i++) {
		t_line line = map->lines[i];
		t_vector3 s = map->d[line.s];
		t_vector3 e = map->d[line.e];
		draw_line(img, (t_point){s.x, s.y, C_YELLOW}, (t_point){e.x, e.y, C_YELLOW});
	}
	e++	;
	return (0);
}

int	render_next_frame(t_data *data)
{
	data->frame++;
	data->camera.rot.y += 1;
	mlx_mouse_get_pos(data->win, &data->extra.mouse.x, &data->extra.mouse.y);
	ft_memset(data->img.addr, 0, WIDTH * HEIGHT * data->img.bits_per_pixel / 8);
	render_frame(&data->img, data->map, &data->camera, &data->extra);
	mlx_put_image_to_window(data->mlx, data->win, data->img.obj, 0, 0);
	return (0);
}

int	key_down_events(int key_code, t_data *data)
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
	else if (key_code == KEY_UP)
		data->camera.rot.z += 15;
	else if (key_code == KEY_DOWN)
		data->camera.rot.z -= 15;
	else if (key_code == KEY_LEFT)
		data->camera.rot.y += 15;
	else if (key_code == KEY_RIGHT)
		data->camera.rot.y -= 15;
	return (0);
}

int	mouse_events(int button, int x, int y, t_data *param)
{
	x++;
	y++;
	if (button == MOUSE_WHEEL_UP)
		param->camera.zoom *= 1.2;
	if (button == MOUSE_WHEEL_DOWN && param->camera.zoom > 0.1)
		param->camera.zoom /= 1.2;
	if (param->camera.zoom < 0.1)
		param->camera.zoom = 0.1;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		exit(1);
	ft_memset(&data, 0, sizeof(data));
	data.mlx = mlx_init();
	if (data.mlx == 0)
		exit(1);
	data.map = create_map(argv[1]);
	data.camera.pos.z = -100000;
	data.camera.zoom = 10;
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "fdf");
	data.img.size = (t_point){WIDTH, HEIGHT, 0};
	data.img.obj = mlx_new_image(data.mlx, data.img.size.x, data.img.size.y);
	data.img.addr = mlx_get_data_addr(data.img.obj, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	mlx_put_image_to_window(data.mlx, data.win, data.img.obj, 0, 0);
	mlx_key_hook(data.win, key_down_events, &data);
	mlx_mouse_hook(data.win, mouse_events, &data);
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
}
