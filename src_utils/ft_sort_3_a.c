/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:56:11 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/28 12:18:34 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static void	ft_contents_3(int *fc, int *sc, int *tc, t_ps_stack *stack)
{
	t_dllist	*frst;
	t_dllist	*scd;
	t_dllist	*thrd;

	frst = stack->dll;
	scd = frst->next;
	thrd = scd->next;
	*fc = ((t_stack_el *)frst->content)->order;
	*sc = ((t_stack_el *)scd->content)->order;
	*tc = ((t_stack_el *)thrd->content)->order;
}

void	ft_sort_3_a(t_push_swap_data *d)
{
	int	fc;
	int	sc;
	int	tc;

	ft_contents_3(&fc, &sc, &tc, d->stack_a);
	if (fc > sc && fc > tc)
		psd_apply_cmd(d, ra);
	else if (sc > fc && sc > tc)
		psd_apply_cmd(d, rra);
	ft_sort_2_a_b(d);
}
