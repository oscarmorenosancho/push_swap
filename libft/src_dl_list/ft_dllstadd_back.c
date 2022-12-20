/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:25:21 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/20 17:03:09 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dl_list.h"

void	ft_dllstadd_back(t_dllist **lst, t_dllist *nn)
{
	t_dllist	*last;

	if (lst && nn)
	{
		if (*lst)
		{
			last = (*lst)->prev;
			last->next = nn;
			(*lst)->prev = nn;
			nn->next = *lst;
			nn->prev = last;
		}
		else
		{
			nn->next = nn;
			nn->prev = nn;
			*lst = nn;
		}
	}
}
