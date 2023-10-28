/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:18:09 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 13:36:30 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_bonus.h>

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cur;

	cur = lst;
	while (cur)
	{
		if (cur->next)
			cur = cur->next;
		else
			return (cur);
	}
	return (cur);
}
