/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:40:25 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/08 08:41:09 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

t_vector	vect(double x, double y, double z);
t_vector	vsum(t_vector v1, t_vector v2);
t_vector	vsub(t_vector v1, t_vector v2);
t_vector	vrev(t_vector v1);
t_vector	vmul(t_vector v1, double v2);
t_vector	vpdt(t_vector v1, t_vector v2);
double		vdot(t_vector v1, t_vector v2);
double		vmag(t_vector v1);
t_vector	vnor(t_vector v1);

#endif