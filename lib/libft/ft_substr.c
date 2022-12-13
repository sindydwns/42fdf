/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:30:57 by sindydwns         #+#    #+#             */
/*   Updated: 2022/09/09 14:30:14 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	size;

	if (s == 0)
		return (0);
	size = ft_strlen(s);
	if (start > size)
		start = size;
	if (start + len > size)
		len = size - start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	s = s + start;
	result[len] = 0;
	while (len-- > 0)
		result[len] = s[len];
	return (result);
}
