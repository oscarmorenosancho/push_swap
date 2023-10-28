/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ins_into_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:22:53 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 23:10:48 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_utils.h>

static void	ft_contents_4_1(int *a, int *b, t_push_swap_data *d)
{
	t_dllist	*al[4];
	t_dllist	*bl[1];
	size_t		i;

	bl[0] = d->stack_b->dll;
	b[0] = ((t_stack_el *)bl[0]->content)->order;
	al[0] = d->stack_a->dll;
	a[0] = ((t_stack_el *)al[0]->content)->order;
	i = 1;
	while (i < 4)
	{
		al[i] = al[i - 1]->next;
		a[i] = ((t_stack_el *)al[i]->content)->order;
		i++;
	}
}

static void	ft_into_y(t_push_swap_data *d, size_t in4, size_t y)
{
	int		a[4];
	int		b[1];
	int		in4_y;

	ft_contents_4_1(a, b, d);
	in4_y = (in4 + y) % 4;
	if (in4_y < 2)
		psd_apply_cmd_xn(d, ra, in4_y, 1);
	else
		psd_apply_cmd_xn(d, rra, 4 - in4_y, 1);
	psd_apply_cmd(d, pa, 1);
	if (y < 3)
		psd_apply_cmd_xn(d, rra, y, 1);
	else
		psd_apply_cmd_xn(d, ra, 5 - y, 1);
}

void	ft_ins_into_4(t_push_swap_data *d, size_t in4)
{
	int		a[4];
	int		b[1];
	int		x;

	x = in4;
	ft_contents_4_1(a, b, d);
	if (b[0] < a[x])
		ft_into_y(d, in4, 0);
	else if (b[0] > a[x] && b[0] < a[(x + 1) % 4])
		ft_into_y(d, in4, 1);
	else if (b[0] > a[(x + 1) % 4] && b[0] < a[(x + 2) % 4])
		ft_into_y(d, in4, 2);
	else if (b[0] > a[(x + 2) % 4] && b[0] < a[(x + 3) % 4])
		ft_into_y(d, in4, 3);
	else
		ft_into_y(d, in4, 4);
}
