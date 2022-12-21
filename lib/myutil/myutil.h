/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myutil.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:04:31 by yonshin           #+#    #+#             */
/*   Updated: 2022/12/22 01:01:49 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYUTIL_H
# define MYUTIL_H
# include <stdlib.h>
# define ERR_PARAM "ERR_PARAM"

void	*ft_calloc_guard(size_t size);
void	err_exit(const char *msg);

#endif
