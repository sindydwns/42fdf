/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:34:06 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/29 17:55:37 by yonshin          ###   ########.fr       */
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
