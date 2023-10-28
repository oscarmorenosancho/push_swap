/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllst_reduce.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:17:40 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 13:37:32 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dl_list.h>

void	ft_dllst_reduce(t_dllist *lst, \
	void (*f)(unsigned int, t_dllist *, void *), void *arg)
{
	t_dllist	*cur;
	int			next_is_head;
	int			i;

	next_is_head = 0;
	cur = lst;
	i = 0;
	if (f)
	{
		while (cur && ! next_is_head)
		{	
			(*f)(i, (void *)cur, arg);
			cur = cur->next;
			next_is_head = (cur == lst);
			i++;
		}
	}
}
