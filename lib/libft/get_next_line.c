/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:02:51 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/13 14:07:23 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static t_test	*list;
	int				err;

	if (fd < 0)
		return (0);
	err = 0;
	return (get_next_line_recursive(&list, fd, 0, &err));
}
