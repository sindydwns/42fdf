/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:20:59 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/30 01:22:03 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define KEY_ESC 53
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_DOT 43
# define KEY_COMMA 47
# define KEY_QUESTION 44
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_R 15
# define KEY_F 3
# define KEY_T 17
# define KEY_G 5
# define KEY_Q 12
# define KEY_E 14
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_SHIFT 257
# define KEY_PLUS 24
# define KEY_MINUS 27
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define MAX_KEYCODE 300

# define DEFER 0.85

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
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
	t_vector3	tpos;
	t_vector3	rot;
	t_vector3	trot;
	double		zoom;
	double		tzoom;
}	t_camera;

typedef struct s_extra
{
	t_point	mouse;
	int		key[MAX_KEYCODE];
}	t_extra;

typedef struct s_data
{
	void				*mlx;
	void				*win;
	t_img				img;
	t_camera			camera;
	t_extra				ex;
	t_obj				*map;
}	t_data;

t_obj		*create_map(const char *path);
void		destroy_map(t_obj *map);
int			close_event(void);
int			keydown_event(int keycode, t_data *data);
int			keyup_event(int keycode, t_data *data);
int			mouse_event(int button, int x, int y, t_data *param);
t_matrix4	get_move_matrix(t_vector3 v);
t_matrix4	get_rotate_matrix(t_vector3 v);
t_matrix4	get_scale_matrix(t_vector3 v);
void		keystrock(t_data *data);

#endif
