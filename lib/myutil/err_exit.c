/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:56:11 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/22 01:00:03 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "myutil.h"

void	err_exit(const char *msg)
{
	int	len;

	if (msg == 0 || *msg == 0)
		exit(1);
	len = 0;
	while (msg[len])
		len++;
	write(1, msg, len);
	exit(1);
}
