/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:33:58 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/02 13:30:15 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*dup;

	size = 0;
	while (s1[size])
		size++;
	dup = (char *)malloc(sizeof(char) * size + 1);
	if (dup == 0)
		return (0);
	size = -1;
	while (s1[++size])
		dup[size] = s1[size];
	dup[size] = 0;
	return (dup);
}
