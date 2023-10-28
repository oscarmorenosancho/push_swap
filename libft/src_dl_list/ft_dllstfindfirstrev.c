/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstfindfirstrev.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:11:29 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 21:58:09 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dl_list.h>

t_dllist	*ft_dllstfindfirstrev(int *loc, t_dllist *lst, \
			int (*f)(unsigned int, t_dllist *, void *), void *arg)
{
	t_dllist	*cur;
	int			prev_is_head;
	int			i;

	if (f && arg && lst)
	{
		prev_is_head = 0;
		cur = lst;
		i = 0;
		while (cur && ! prev_is_head && (loc && (*loc < 1 || i < *loc)))
		{
			if ((*f)(i, cur, arg))
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
