/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllst_extract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:52:46 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 13:37:32 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dl_list.h>

t_dllist	*ft_dllst_extract(t_dllist **lst)
{
	t_dllist	*last;
	t_dllist	*head;
	t_dllist	*scd;

	if (lst && *lst)
	{
		head = *lst;
		last = head->prev;
		scd = head->next;
		if (head == last)
		{
			*lst = NULL;
			return (head);
		}
		last->next = scd;
		scd->prev = last;
		head->next = head;
		head->prev = head;
		*lst = scd;
		return (head);
	}
	return (NULL);
}
