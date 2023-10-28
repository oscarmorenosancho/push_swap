/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_stack_el.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:44:13 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 23:10:49 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_utils.h>

t_dllist	*ft_new_stack_el(int nbr, int order)
{
	t_stack_el	*content;
	t_dllist	*node;

	content = malloc(sizeof(t_stack_el));
	if (!content)
		return (NULL);
	content->nbr = nbr;
	content->order = order;
	node = ft_dllstnew(content);
	if (! node)
		free(content);
	return (node);
}
