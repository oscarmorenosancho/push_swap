/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:52:33 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 23:33:17 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dl_list.h>

void	ft_dllstiter(t_dllist *lst, void (*f)(void *))
{
	t_dllist	*cur;
	int			next_is_head;

	next_is_head = 0;
	cur = lst;
	if (f)
	{
		while (cur && ! next_is_head)
		{
			(*f)((void *)cur->content);
			cur = cur->next;
			next_is_head = (cur == lst);
		}
	}
}
