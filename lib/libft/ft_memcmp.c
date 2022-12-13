/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:47:58 by yonshin           #+#    #+#             */
/*   Updated: 2022/07/12 12:02:37 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cursor1;
	unsigned char	*cursor2;
	size_t			idx;

	cursor1 = (unsigned char *)s1;
	cursor2 = (unsigned char *)s2;
	idx = -1;
	while (++idx < n)
	{
		if (cursor1[idx] != cursor2[idx])
			return (cursor1[idx] - cursor2[idx]);
	}
	return (0);
}
