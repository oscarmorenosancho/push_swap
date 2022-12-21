/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstfindfirstinrange.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:45:20 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/21 15:52:19 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static int	ft_is_in_range(unsigned int i, void *item, void *arg)
{
	int			*range;
	t_stack_el	*el;
	int			min;
	int			max;

	range = (int *)arg;
	min = range[0];
	max = range[1];
	if (min > max)
	{
		max = range[0];
		min = range[1];
	}
	(void)i;
	el = item;
	return (el->order >= min && el->order <= max);
}

t_dllist	*ft_dllstfindfirstinrange(int *loc, t_dllist *lst, int *range)
{
	return (ft_dllstfindfirst(loc, lst, &ft_is_in_range, range));
}

t_dllist	*ft_dllstfindfirstinrangerev(int *loc, t_dllist *lst, int *range)
{
	return (ft_dllstfindfirstrev(loc, lst, &ft_is_in_range, range));
}
