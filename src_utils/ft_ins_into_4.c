/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ins_into_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:22:53 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/27 16:49:35 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

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
	ft_putnbr_fd(a[0], 1);
	while (i < 4)
	{
		al[i] = al[i - 1]->next;
		a[i] = ((t_stack_el *)al[i]->content)->order;
		ft_putstr_fd(", ", 1);
		ft_putnbr_fd(a[i], 1);
		i++;
	}
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(b[0], 1);
	ft_putstr_fd("\n", 1);
}

static void	ft_into_y(t_push_swap_data *d, size_t in4, size_t y)
{
	int		a[4];
	int		b[1];

	ft_contents_4_1(a, b, d);
	if (((in4 + y) % 4) > 2)
		psd_apply_cmd_xn(d, rra, ((in4 + y) % 4) - 2);
	else
		psd_apply_cmd_xn(d, rr, 1 - ((in4 + y) % 4));
	psd_apply_cmd(d, pa);
	if (((in4 + y) % 4) > 2)
		psd_apply_cmd_xn(d, rr, ((in4 + y) % 4) - 2);
	else
		psd_apply_cmd_xn(d, rra, 1 - ((in4 + y) % 4));
}

void	ft_ins_into_4(t_push_swap_data *d, size_t in4)
{
	int		a[4];
	int		b[1];

	ft_contents_4_1(a, b, d);
	if (b[0] > a[(in4 + 3) % 4] || b[0] < a[in4])
		ft_into_y(d, in4, 0);
	else if (b[0] > a[in4] && b[0] < a[(in4 + 1) % 4])
		ft_into_y(d, in4, 1);
	else if (b[0] > a[(in4 + 1) % 4] && b[0] < a[(in4 + 2) % 4])
		ft_into_y(d, in4, 2);
	else
		ft_into_y(d, in4, 3);
}
