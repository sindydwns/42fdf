/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:40:25 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/17 16:23:49 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector3
{
	double	x;
	double	y;
	double	z;
}	t_vector3;

typedef struct s_vector4
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vector4;

t_vector3	vect3(double x, double y, double z);
t_vector3	vsum3(t_vector3 v1, t_vector3 v2);
t_vector3	vsub3(t_vector3 v1, t_vector3 v2);
t_vector3	vrev3(t_vector3 v1);
t_vector3	vmul3(t_vector3 v1, double v2);
double		vdot3(t_vector3 v1, t_vector3 v2);
double		vmag3(t_vector3 v1);
t_vector3	vnor3(t_vector3 v1);

t_vector4	vect4(double x, double y, double z, double w);
t_vector4	vsum4(t_vector4 v1, t_vector4 v2);
t_vector4	vsub4(t_vector4 v1, t_vector4 v2);
t_vector4	vrev4(t_vector4 v1);
t_vector4	vmul4(t_vector4 v1, double v2);
double		vdot4(t_vector4 v1, t_vector4 v2);
double		vmag4(t_vector4 v1);
t_vector4	vnor4(t_vector4 v1);

#endif