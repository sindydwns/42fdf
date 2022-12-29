/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_splited_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:53:00 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/30 08:20:21 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myutil.h"

void	free_splited_str(char **strs)
{
	int	i;

	if (strs == 0)
		return ;
	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}
