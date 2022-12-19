/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:08:15 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/19 13:06:33 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dl_list.h"

void	ft_dllstadd_front(t_dllist **lst, t_dllist *nn)
{
	t_dllist	*last;
	t_dllist	*head;

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
		*lst = nn;
		(*lst)->next = *lst;
		(*lst)->prev = *lst;
	}
}
