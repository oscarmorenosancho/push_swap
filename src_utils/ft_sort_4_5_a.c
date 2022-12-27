/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_4_5_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:31:31 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/27 13:18:13 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static void	ft_contents_x_1(int *a, int *b, t_push_swap_data *d, size_t sz_a)
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
	while (i < sz_a)
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

static void	ft_rax_pa_rray(t_push_swap_data *d, size_t x, int s5)
{
	int	a[4];
	int	b[1];

	psd_apply_cmd_xn(d, ra, x);
	psd_apply_cmd(d, pa);
	if (! s5)
	{
		psd_apply_cmd_xn(d, rra, x);
		return ;
	}
	ft_contents_x_1(a, b, d, d->stack_a->size);

	//?????
}

static void	ft_rrax_pa_ray(t_push_swap_data *d, size_t x, int s5)
{
	int	a[3];
	int	b[1];

	psd_apply_cmd_xn(d, rra, x);
	psd_apply_cmd(d, pa);
	if (! s5)
	{
		psd_apply_cmd_xn(d, ra, x);
		return ;
	}
	ft_contents_x_1(a, b, d, d->stack_a->size);
}

void	ft_sort_4_5_a(t_push_swap_data *d)
{
	int	a[4];
	int	b[1];
	int	s5;

	s5 = (d->stack_a->size == 5);
	psd_apply_cmd_xn(d, pb, d->stack_a->size - 3);
	ft_sort_3_a(d);
	ft_contents_x_1(a, b, d, d->stack_a->size);
	if (b[0] < a[0])
		psd_apply_cmd(d, pa);
	else if (b[0] < a[1])
		ft_rrax_pa_ray(d, 1, s5);
	else if (b[0] < a[2])
		ft_rrax_pa_ray(d, 2, s5);
	else
		ft_rax_pa_rray(d, 1, s5);
}
