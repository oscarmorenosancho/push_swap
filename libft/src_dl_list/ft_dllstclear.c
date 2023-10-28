/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:38:48 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 13:37:32 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dl_list.h>

void	ft_dllstclear(t_dllist **lst, void (*del)(void *))
{
	t_dllist	*head;

	if (lst)
	{
		if (! *lst)
			return ;
		(*lst)->prev->next = NULL;
		while (*lst)
		{
			head = *lst;
			*lst = head->next;
			ft_dllstdelone(head, del);
		}
	}
}
