/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_do_when_sorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:07:44 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 23:10:48 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_utils.h>

int	ft_to_do_when_sorted(t_push_swap_data *d, t_sort_anal *s_anal)
{
	int		is_sorted;
	int		min_loc;
	int		ret;

	is_sorted = s_anal->is_sorted;
	min_loc = s_anal->min_loc;
	free_x ((void **)&s_anal);
	ret = (is_sorted && d->stack_b->size == 0);
	if (ret && min_loc > 0)
	{
		if (min_loc < (int)(d->stack_a->size / 2))
			psd_apply_cmd_xn(d, rr, min_loc, 1);
		else
			psd_apply_cmd_xn(d, rrr, d->stack_a->size - min_loc, 1);
	}
	return (ret);
}
