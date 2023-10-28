/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstfindfirst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:14:29 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 21:03:52 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dl_list.h>

t_dllist	*ft_dllstfindfirst(int *loc, t_dllist *lst, \
			int (*f)(unsigned int, void *, void *), void *arg)
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
			if ((*f)(i, (void *)cur->content, arg))
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
