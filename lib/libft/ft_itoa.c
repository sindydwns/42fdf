/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:39:02 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/09 14:29:11 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*reverse_dup(char *str, size_t size)
{
	char	*result;
	size_t	idx;

	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result == 0)
		return (0);
	idx = -1;
	while (++idx < size)
		result[idx] = str[size - idx - 1];
	result[size] = 0;
	return (result);
}

char	*ft_itoa(int n)
{
	char	temp[42];
	int		idx;
	int		minus;

	idx = 0;
	minus = n < 0;
	if (n > 0)
		n = -n;
	while (1)
	{
		temp[idx++] = '0' - (n % 10);
		n = n / 10;
		if (n == 0)
			break ;
	}
	if (minus)
		temp[idx++] = '-';
	return (reverse_dup(temp, idx));
}
