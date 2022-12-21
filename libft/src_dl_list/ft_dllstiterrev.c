/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstiterrev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:34:31 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/21 11:53:44 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dl_list.h"

void	ft_dllstiterrev(t_dllist *lst, void (*f)(void *))
{
	t_dllist	*cur;
	int			next_is_last;

	next_is_last = 0;
	if (!lst)
		return ;
	cur = lst->prev;
	if (f)
	{
		while (cur && ! next_is_last)
		{	
			(*f)((void *)cur->content);
			cur = cur->prev;
			next_is_last = (cur == lst->prev);
		}
	}
}
