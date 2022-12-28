/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstfindfirstrev.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:02:43 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/28 15:55:10 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dl_list.h"

t_dllist	*ft_dllstfindfirstrev(int *loc, t_dllist *lst, \
			int (*f)(unsigned int, void *, void *), void *arg)
{
	t_dllist	*cur;
	int			prev_is_head;
	int			i;

	if (f && arg && lst)
	{
		prev_is_head = 0;
		cur = lst;
		i = 0;
		while (cur && ! prev_is_head && ((loc && *loc > 0) || i < *loc))
		{	
			if ((*f)(i, (void *)cur->content, arg))
			{
				if (loc)
					*loc = i;
				return (cur);
			}
			cur = cur->prev;
			prev_is_head = (cur == lst);
			i++;
		}
	}
	if (loc)
		*loc = -1;
	return (NULL);
}
