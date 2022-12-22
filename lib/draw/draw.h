/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:34:06 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/22 19:58:19 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# ifndef WIDTH
#  define WIDTH 1920
# endif
# ifndef HEIGHT
#  define HEIGHT 1080
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
	int c;
}	t_point;

typedef struct s_img {
	void	*obj;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_point	size;
}	t_img;

typedef struct s_option
{
	int	color;
}	t_option;

int	draw_pixel(t_img *target, t_point point);
int	draw_line(t_img *target, t_point start, t_point end);
int	draw_rect(t_img *target, t_point start, t_point end);
int	draw_circle(t_img *target, t_point center, int radius);

#endif
