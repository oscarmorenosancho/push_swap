/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:38:48 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/20 17:31:55 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dl_list.h"

void	ft_dllstclear(t_dllist **lst, void (*del)(void *))
{
	t_dllist	*head;

	if (lst)
	{
		(*lst)->prev->next = NULL;
		while (*lst)
		{
			head = *lst;
			*lst = head->next;
			if (del)
				(*del)(head->content);
			if (head)
				free (head);
		}
	}
}
