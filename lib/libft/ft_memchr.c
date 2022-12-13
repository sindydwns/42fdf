/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:11:28 by yonshin           #+#    #+#             */
/*   Updated: 2022/07/12 12:02:34 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cursor;
	size_t			idx;

	cursor = (unsigned char *)s;
	idx = -1;
	while (++idx < n)
	{
		if (cursor[idx] == (unsigned char)c)
			return (cursor + idx);
	}
	return (0);
}
