/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 07:24:03 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 07:54:25 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strupper(char *str)
{
	char	*res;
	int		idx;

	if (str == 0)
		return (0);
	res = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (res == 0)
		return (0);
	idx = -1;
	while (str[++idx])
		res[idx] = ft_toupper(str[idx]);
	res[idx] = 0;
	return (res);
}
