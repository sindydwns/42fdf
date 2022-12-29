/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:48:53 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/30 01:36:09 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static t_matrix4	get_matrix(t_obj *map)
{
	t_matrix4	obj_matrix;

	obj_matrix = m4_unit();
	obj_matrix = m4_mul_m4(get_scale_matrix(map->scl), obj_matrix);
	obj_matrix = m4_mul_m4(get_rotate_matrix(map->rot), obj_matrix);
	obj_matrix = m4_mul_m4(get_move_matrix(map->pos), obj_matrix);
	return (obj_matrix);
}

static void	draw_axis(t_img *img, t_camera *cam)
{
	const t_vector4	a = (t_vector4){WIDTH / 2, HEIGHT / 2, 0, 0};
	const t_vector4	zr = vsum4(m4_mul_v4(cam->matrix, vect4(0, 0, 0, 1)), a);
	const t_vector4	ax = vsum4(m4_mul_v4(cam->matrix, vect4(1000, 0, 0, 1)), a);
	const t_vector4	ay = vsum4(m4_mul_v4(cam->matrix, vect4(0, 1000, 0, 1)), a);
	const t_vector4	az = vsum4(m4_mul_v4(cam->matrix, vect4(0, 0, 1000, 1)), a);

	draw_line(img, (t_point){ax.x, ax.y, C_RED}, (t_point){zr.x, zr.y, C_RED});
	draw_line(img, (t_point){ay.x, ay.y, C_GRN}, (t_point){zr.x, zr.y, C_GRN});
	draw_line(img, (t_point){az.x, az.y, C_BLU}, (t_point){zr.x, zr.y, C_BLU});
}

static int	render_frame(t_img *img, t_obj *map, t_camera *cam)
{	
	const t_matrix4	mat = m4_mul_m4(cam->matrix, get_matrix(map));
	int				i;
	t_vector3		point1;
	t_vector3		point2;
	t_vector4		v4;

	i = -1;
	while (++i < map->dot_len)
	{
		point1 = map->dots[i];
		v4 = m4_mul_v4(mat, vect4(point1.x, point1.y, point1.z, 1));
		map->d[i] = vect3(v4.x + WIDTH / 2, v4.y + HEIGHT / 2, v4.z);
	}
	i = -1;
	while (++i < map->line_len)
	{
		point1 = map->d[map->lines[i].s];
		point2 = map->d[map->lines[i].e];
		if (point1.z > 0 || point2.z > 0)
			continue ;
		draw_line(img, (t_point){point1.x, point1.y, C_YLW}, \
			(t_point){point2.x, point2.y, C_YLW});
	}
	draw_axis(img, cam);
	return (0);
}

static int	render_next_frame(t_data *data)
{
	t_camera	*c;

	c = &data->camera;
	c->tpos = vsum3(vmul3(c->tpos, DEFER), vmul3(c->pos, 1 - DEFER));
	c->trot = vsum3(vmul3(c->trot, DEFER), vmul3(c->rot, 1 - DEFER));
	c->tzoom = c->tzoom * DEFER + c->zoom * (1 - DEFER);
	c->matrix = m4_unit();
	c->matrix = m4_mul_m4(get_move_matrix(vrev3(c->tpos)), c->matrix);
	c->matrix = m4_mul_m4(m4_trans(get_rotate_matrix(c->trot)), c->matrix);
	c->matrix = m4_mul_m4(get_scale_matrix(\
		(t_vector3){c->tzoom, c->tzoom, c->tzoom}), c->matrix);
	mlx_mouse_get_pos(data->win, &data->ex.mouse.x, &data->ex.mouse.y);
	ft_memset(data->img.addr, 0, WIDTH * HEIGHT * data->img.bits_per_pixel / 8);
	keystrock(data);
	render_frame(&data->img, data->map, &data->camera);
	mlx_put_image_to_window(data->mlx, data->win, data->img.obj, 0, 0);
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
	data.camera.zoom = 1;
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, argv[1]);
	data.img.size = (t_point){WIDTH, HEIGHT, 0};
	data.img.obj = mlx_new_image(data.mlx, data.img.size.x, data.img.size.y);
	data.img.addr = mlx_get_data_addr(data.img.obj, &data.img.bits_per_pixel, \
		&data.img.line_length, &data.img.endian);
	mlx_put_image_to_window(data.mlx, data.win, data.img.obj, 0, 0);
	mlx_mouse_hook(data.win, mouse_event, &data);
	mlx_hook(data.win, ON_DESTROY, 0, close_event, &data);
	mlx_hook(data.win, ON_KEYDOWN, 0, keydown_event, &data);
	mlx_hook(data.win, ON_KEYUP, 0, keyup_event, &data);
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
