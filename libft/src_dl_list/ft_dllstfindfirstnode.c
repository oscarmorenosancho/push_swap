/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstfindfirstnode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:08:48 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/10 16:56:19 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dl_list.h"

t_dllist	*ft_dllstfindfirstnode(int *loc, t_dllist *lst, \
			int (*f)(unsigned int, t_dllist *, void *), void *arg)
{
	t_dllist	*cur;
	int			next_is_head;
	int			i;

	if (f && arg && lst)
	{
		next_is_head = 0;
		cur = lst;
		i = 0;
		while (cur && ! next_is_head && (loc && (*loc < 1 || i < *loc)))
		{	
			if ((*f)(i, cur, arg))
			{
				if (loc)
					*loc = i;
				return (cur);
			}
			cur = cur->next;
			next_is_head = (cur == lst);
			i++;
		}
	}
	if (loc)
		*loc = -1;
	return (NULL);
}
