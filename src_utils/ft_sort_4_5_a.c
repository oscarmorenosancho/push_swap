/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_4_5_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:31:31 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/29 17:40:46 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static void	ft_contents_x_1(int *a, int *b, t_push_swap_data *d)
{
	t_dllist	*al[3];
	t_dllist	*bl[1];
	size_t		i;

	bl[0] = d->stack_b->dll;
	b[0] = ((t_stack_el *)bl[0]->content)->order;
	al[0] = d->stack_a->dll;
	a[0] = ((t_stack_el *)al[0]->content)->order;
	i = 1;
	while (i < 3)
	{
		al[i] = al[i - 1]->next;
		a[i] = ((t_stack_el *)al[i]->content)->order;
		i++;
	}
}

static void	ft_rrx_pa(t_push_swap_data *d, size_t x, int s5)
{
	if (x == 1)
		psd_apply_cmd(d, ra, 1);
	else if (x == 2)
		psd_apply_cmd(d, rra, 1);
	psd_apply_cmd(d, pa, 1);
	if (! s5)
	{
		if (x == 1)
			psd_apply_cmd(d, rra, 1);
		else if (x == 2)
			psd_apply_cmd_xn(d, ra, 2, 1);
		else if (x == 3)
			psd_apply_cmd(d, ra, 1);
	}
	else
		ft_ins_into_4(d, (4 - (int)x) % 4);
}

void	ft_sort_4_5_a(t_push_swap_data *d)
{
	int	a[3];
	int	b[1];
	int	s5;

	s5 = (d->stack_a->size == 5);
	psd_apply_cmd_xn(d, pb, d->stack_a->size - 3, 1);
	ft_sort_3_a(d);
	ft_contents_x_1(a, b, d);
	if (b[0] < a[0])
		ft_rrx_pa(d, 0, s5);
	else if (b[0] < a[1])
		ft_rrx_pa(d, 1, s5);
	else if (b[0] < a[2])
		ft_rrx_pa(d, 2, s5);
	else
		ft_rrx_pa(d, 3, s5);
}
