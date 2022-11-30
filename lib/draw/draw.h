/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:34:06 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/01 00:53:54 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# ifndef WIDTH
#  define WIDTH 800
# endif
# ifndef HEIGHT
#  define HEIGHT 600
# endif

# define C_RED 0xFF0000
# define C_GREEN 0x00FF00
# define C_BLUE 0x0000FF
# define C_YELLOW 0xFFFF00
# define C_WHITE 0xFFFFFF

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct	s_img {
	void	*obj;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_option
{
	int color;
}	t_option;


typedef struct	s_data {
	void				*mlx;
	void				*win;
	unsigned long long	frame;
	t_img				img;
}	t_data;

int	draw_pixel(t_img *target, t_point point, int color);
int	draw_line(t_img *target, t_point start, t_point end, int color);
int	draw_rect(t_img *target, t_point start, t_point end, int color);
int	draw_circle(t_img *target, t_point center, int radius, int color);

#endif
