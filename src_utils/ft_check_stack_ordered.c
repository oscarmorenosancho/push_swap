/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack_ordered.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:33:40 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/10 16:30:26 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static int	ft_is_le_prev(unsigned int i, void *it_cont, void *arg)
{
	int			*prev_val;
	int			res;
	t_stack_el	*el;

	(void)i;
	prev_val = arg;
	el = it_cont;
	res = (el->order <= *prev_val);
	*prev_val = el->order;
	return (res);
}

int	ft_check_stack_ordered(t_dllist *dll)
{
	int	loc;
	int	prev_val;

	if (! dll)
		return (1);
	prev_val = -1;
	loc = -1;
	return (! ft_dllstfindfirst(&loc, dll, &ft_is_le_prev, &prev_val));
}
