/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:56:11 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/23 18:23:35 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static void	ft_contents_3(int *fc, int *sc, int *tc, t_push_swap_data *d)
{
	t_dllist	*frst;
	t_dllist	*scd;
	t_dllist	*thrd;

	frst = (t_dllist *)(d->stack_a);
	scd = frst->next;
	thrd = scd->next;
	*fc = ((t_stack_el *)frst->content)->order;
	*sc = ((t_stack_el *)scd->content)->order;
	*tc = ((t_stack_el *)thrd->content)->order;
}

void	ft_sort_3_list(t_push_swap_data *d)
{
	int	fc;
	int	sc;
	int	tc;

	ft_contents_3(&fc, &sc, &tc, d);
	if (fc > sc && fc > tc)
	{
		psd_apply_cmd(d, rra);
		ft_contents_3(&fc, &sc, &tc, d);
	}
	else if (sc > fc && sc > tc)
	{
		psd_apply_cmd(d, ra);
		ft_contents_3(&fc, &sc, &tc, d);
	}
	if (fc > sc)
	{
		psd_apply_cmd(d, sa);
		ft_contents_3(&fc, &sc, &tc, d);
	}
}
