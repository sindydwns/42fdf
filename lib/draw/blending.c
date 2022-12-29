/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blending.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:26:59 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/29 22:58:11 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	blending(int c1, int c2, int i, int max)
{
	int	res;
	int	mask;

	res = 0;
	mask = 0xFF0000;
	while (mask)
	{
		res |= (int)((c1 & mask) * (1 - (float)i / max) + \
			(c2 & mask) * (float)i / max) & mask;
		mask >>= 8;
	}
	return (res);
}
