/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:18:32 by yonshin           #+#    #+#             */
/*   Updated: 2022/07/12 12:03:07 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*cursor;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen((char *)dst);
	src_len = ft_strlen((char *)src);
	cursor = dst;
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	dstsize -= dst_len;
	while (*cursor)
		cursor++;
	while (*src && dstsize - 1 != 0)
	{
		*cursor = *src;
		cursor++;
		src++;
		dstsize--;
	}
	*cursor = 0;
	return (dst_len + src_len);
}
