/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_guard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:04:01 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/22 00:10:32 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myutil.h"

static void	*ft_calloc(size_t count, size_t size)
{
	size_t			total;
	unsigned char	*tmp;

	if (size && count > SIZE_MAX / size)
		return (0);
	total = count * size;
	tmp = (unsigned char *)malloc(total);
	if (tmp == 0)
		return (0);
	while (total-- > 0)
		tmp[total] = 0;
	return (tmp);
}

void	*ft_calloc_guard(size_t size)
{
	void	*res;

	res = ft_calloc(1, size);
	if (res == NULL)
		exit(1);
	return (res);
}
