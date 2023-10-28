/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:12:02 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 13:37:32 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dl_list.h>

int	ft_dllstsize(t_dllist *lst)
{
	int			i;
	t_dllist	*cur;
	int			next_is_head;

	if (! lst)
		return (0);
	cur = lst;
	i = 0;
	next_is_head = 0;
	while (cur && !next_is_head)
	{
		i++;
		cur = cur->next;
		next_is_head = (cur == lst);
	}
	return (i);
}
