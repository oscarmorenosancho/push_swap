/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:50:22 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/28 17:05:47 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static void	ft_contents_2(int *fc, int *sc, t_ps_stack *stack)
{
	t_dllist	*frst;
	t_dllist	*scd;

	frst = stack->dll;
	scd = frst->next;
	*fc = ((t_stack_el *)frst->content)->order;
	*sc = ((t_stack_el *)scd->content)->order;
}

void	ft_sort_2_a_b(t_push_swap_data *d)
{
	int	fc_a;
	int	sc_a;
	int	fc_b;
	int	sc_b;

	if (d->stack_a->size > 1)
	{
		ft_contents_2(&fc_a, &sc_a, d->stack_a);
		if (fc_a > sc_a)
		{
			psd_apply_cmd(d, sa);
			if (d->stack_b->size > 1)
			{
				ft_contents_2(&fc_b, &sc_b, d->stack_b);
				if (fc_b < sc_b)
				{
					psd_apply_cmd(d, sb);
				}
			}
		}
	}
}

void	ft_sort_2_b_a(t_push_swap_data *d)
{
	int	fc_a;
	int	sc_a;
	int	fc_b;
	int	sc_b;

	if (d->stack_b->size > 1)
	{
		ft_contents_2(&fc_b, &sc_b, d->stack_b);
		if (fc_b < sc_b)
		{
			psd_apply_cmd(d, sb);
			if (d->stack_a->size > 1)
			{
				ft_contents_2(&fc_a, &sc_a, d->stack_a);
				if (fc_a > sc_a)
				{
					psd_apply_cmd(d, sa);
				}
			}
		}
	}
}

void	ft_sort_2_anb(t_push_swap_data *d)
{
	int	fc_a;
	int	sc_a;
	int	fc_b;
	int	sc_b;

	if (d->stack_b->size > 1 && d->stack_a->size > 1)
	{
		ft_contents_2(&fc_b, &sc_b, d->stack_b);
		ft_contents_2(&fc_a, &sc_a, d->stack_a);
		if (fc_b < sc_b && fc_a > sc_a)
			psd_apply_cmd(d, ss);
	}
}
