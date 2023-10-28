/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:57:38 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 13:37:32 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dl_list.h>

t_dllist	*ft_dllstnew(void *content)
{
	t_dllist	*p;

	p = (t_dllist *)malloc(sizeof (t_dllist));
	if (p)
	{
		p->content = content;
		p->next = p;
		p->prev = p;
	}
	return (p);
}
