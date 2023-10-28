/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:08:15 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 13:37:32 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dl_list.h>

void	ft_dllstadd_front(t_dllist **lst, t_dllist *nn)
{
	t_dllist	*last;
	t_dllist	*head;

	if (lst && nn)
	{
		if (*lst)
		{
			last = (*lst)->prev;
			head = *lst;
			nn->next = head;
			nn->prev = last;
			last->next = nn;
			head->prev = nn;
			*lst = nn;
		}
		else
		{
			nn->next = nn;
			nn->prev = nn;
			*lst = nn;
		}
	}
}
