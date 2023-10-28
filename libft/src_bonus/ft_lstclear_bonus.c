/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:38:48 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 13:36:30 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_bonus.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;

	if (lst)
	{
		while (*lst)
		{
			head = *lst;
			*lst = head->next;
			if (del)
				(*del)(head->content);
			free ((void *)head);
		}
	}
}
