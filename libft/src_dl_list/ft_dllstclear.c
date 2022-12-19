/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:38:48 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/19 14:02:48 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dl_list.h"

void	ft_dllstclear(t_dllist **lst, void (*del)(void *))
{
	t_dllist	*head;
	int			next_is_head;

	next_is_head = 0;
	if (lst)
	{
		while (*lst && ! next_is_head)
		{
			head = *lst;
			next_is_head = (head->next == *lst);
			*lst = head->next;
			if (del)
				(*del)(head->content);
			free ((void *)head);
		}
	}
}
