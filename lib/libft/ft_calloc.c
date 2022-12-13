/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:37:02 by yonshin           #+#    #+#             */
/*   Updated: 2022/07/20 17:46:19 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
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
