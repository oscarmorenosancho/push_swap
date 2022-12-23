/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllst_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:52:46 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/23 12:24:43 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dl_list.h"

void	ft_dllst_swap(t_dllist **lst)
{
	t_dllist	*last;
	t_dllist	*head;
	t_dllist	*scd;
	t_dllist	*thrd;

	if (lst && *lst && (*lst)->next && (*lst)->prev)
	{
		if ((*lst)->next == (*lst) || (*lst)->prev == (*lst))
			return ;
		if ((*lst)->next == (*lst)->prev)
		{
			ft_dllst_rotate(lst);
			return ;
		}
		head = *lst;
		last = head->prev;
		scd = head->next;
		thrd = scd->next;
		last->next = scd;
		scd->next = head;
		head->next = thrd;
		scd->prev = last;
		head->prev = scd;
		thrd->prev = head;
		*lst = scd;
	}
}
