/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:12:02 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/19 13:35:13 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dl_list.h"

int	ft_dllstsize(t_dllist *lst)
{
	int			i;
	t_dllist	*cur;
	int			next_is_head;

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
