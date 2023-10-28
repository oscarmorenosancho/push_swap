/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstfindfirstinrange.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:45:20 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 21:47:44 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static int	ft_is_in_range(unsigned int i, t_dllist *node, void *arg)
{
	int			*range;
	t_stack_el	*el;

	range = (int *)arg;
	(void)i;
	el = node->content;
	if (range[0] <= range[1])
		return (el->order >= range[0] && el->order <= range[1]);
	return (el->order >= range[0] || el->order <= range[1]);
}

t_dllist	*ft_dllstfindfirstinrange(int *loc, t_dllist *lst, int *range)
{
	return (ft_dllstfindfirstnode(loc, lst, &ft_is_in_range, range));
}

t_dllist	*ft_dllstfindfirstinrangerev(int *loc, t_dllist *lst, int *range)
{
	return (ft_dllstfindfirstnoderev(loc, lst, &ft_is_in_range, range));
}
