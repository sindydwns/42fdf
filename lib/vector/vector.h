/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:40:25 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/27 20:46:12 by yonshin          ###   ########.fr       */
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

typedef struct s_matrix3
{
	t_vector3	v1;
	t_vector3	v2;
	t_vector3	v3;
}	t_matrix3;

typedef struct s_matrix4
{
	t_vector4	v1;
	t_vector4	v2;
	t_vector4	v3;
	t_vector4	v4;
}	t_matrix4;

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

t_vector3	m3_mul_v3(t_matrix3 m1, t_vector3 v1);
t_matrix3	m3_mul_m3(t_matrix3 m1, t_matrix3 m2);
t_matrix3	m3_mul(t_matrix3 m1, double m2);
t_matrix3	m3_trans(t_matrix3 m1);
t_matrix3	m3_unit(void);
t_vector4	m4_mul_v4(t_matrix4 m1, t_vector4 v1);
t_matrix4	m4_mul_m4(t_matrix4 m1, t_matrix4 m2);
t_matrix4	m4_mul(t_matrix4 m1, double m2);
t_matrix4	m4_trans(t_matrix4 m1);
t_matrix4	m4_unit(void);

#endif
