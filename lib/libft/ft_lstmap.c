/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 06:35:52 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/04 14:01:15 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_func_1 f, t_action_1 del)
{
	t_list	*result;
	t_list	*last;
	t_list	*new_node;

	result = 0;
	if (lst == 0 || f == 0)
		return (0);
	while (lst)
	{
		new_node = (t_list *)malloc(sizeof(t_list));
		if (new_node == 0)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		new_node->content = f(lst->content);
		new_node->next = 0;
		if (result == 0)
			result = new_node;
		else
			last->next = new_node;
		last = new_node;
		lst = lst->next;
	}
	return (result);
}
