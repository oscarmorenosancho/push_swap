/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:56:38 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/21 14:04:27 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dl_list.h"
#include "../libft.h"

static t_dllist	*ft_applyftonode(t_dllist *curnode, void *(*f)(void *), \
	void (*del)(void *))
{
	t_dllist	*newnode;
	void		*newcontent;

	if (! curnode || ! f)
		return (0);
	newcontent = (*f)(curnode->content);
	if (! newcontent)
		return (0);
	newnode = ft_dllstnew(newcontent);
	if (! newnode)
	{
		(*del)(newcontent);
		return (0);
	}
	return (newnode);
}

t_dllist	*ft_dllstmap(t_dllist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_dllist	*newlist;
	t_dllist	*cur;
	t_dllist	*newnode;
	int			next_is_head;

	newlist = NULL;
	cur = lst;
	next_is_head = 0;
	while (cur && ! next_is_head)
	{
		newnode = ft_applyftonode(cur, f, del);
		if (newnode)
			ft_dllstadd_back(&newlist, newnode);
		else
			ft_dllstclear(&newlist, del);
		if (!newlist)
			return (0);
		cur = cur->next;
		next_is_head = (cur == lst);
	}
	return (newlist);
}
