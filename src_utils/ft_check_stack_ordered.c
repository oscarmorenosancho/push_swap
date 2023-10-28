/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack_ordered.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:33:40 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 23:10:48 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_utils.h>

static int	ft_is_le_prev(unsigned int i, t_dllist *node, void *arg)
{
	int			res;
	t_stack_el	*el;
	t_stack_el	*prev_el;

	(void)i;
	(void)arg;
	el = node->content;
	prev_el = node->prev->content;
	res = (el->order <= prev_el->order);
	return (res);
}

int	ft_check_stack_ordered(t_ps_stack *stk)
{
	int			loc;
	int			size_sorted;
	int			prev_val;
	t_dllist	*ocur;

	if (! stk)
		return (1);
	if (! stk->dll)
		return (1);
	prev_val = -1;
	loc = -1;
	ocur = ft_dllstfindfirst(&loc, stk->dll, &ft_is_le_prev, &prev_val);
	if (ocur)
	{
		ocur = ft_dllstfindfirst(&size_sorted, stk->dll, \
			&ft_is_le_prev, &prev_val);
		return ((size_t)size_sorted >= stk->size);
	}
	return (0);
}
