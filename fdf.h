/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:20:59 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/30 02:06:56 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define KEY_ESC 53
# define ON_KEYDOWN 2
# define ON_DESTROY 17

# include <stdlib.h>
# include "libft.h"
# include "mlx.h"
# include "draw.h"
# include "vector.h"
# include "math.h"
# include "myutil.h"

typedef struct s_line
{
	int	s;
	int	e;
}	t_line;

typedef struct s_obj
{
	t_vector3	*d;
	t_vector3	*dots;
	int			dot_len;
	t_line		*lines;
	int			line_len;
	t_vector3	pos;
	t_vector3	rot;
	t_vector3	scl;
}	t_obj;

typedef struct s_camera
{
	t_matrix4	matrix;
	t_vector3	pos;
	t_vector3	rot;
	double		zoom;
}	t_camera;

typedef struct s_data
{
	void				*mlx;
	void				*win;
	t_img				img;
	t_camera			camera;
	t_obj				*map;
}	t_data;

t_obj		*create_map(const char *path);
void		destroy_map(t_obj *map);
int			close_event(void);
int			keydown_event(int keycode);
t_matrix4	get_move_matrix(t_vector3 v);
t_matrix4	get_rotate_matrix(t_vector3 v);
t_matrix4	get_scale_matrix(t_vector3 v);

#endif
