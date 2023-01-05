/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:14:08 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/05 13:52:10 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_sort_anal(t_sort_anal *s_anal)
{
	ft_putstr_fd("sort analysis of a\n", 2);
	if (s_anal->is_sorted)
		ft_putstr_fd("is sorted\n", 2);
	else
		ft_putstr_fd("is NOT sorted\n", 2);
	ft_putstr_fd("min: ", 2);
	ft_putnbr_fd(s_anal->min, 2);
	ft_putstr_fd("\nmin loc: ", 2);
	ft_putnbr_fd(s_anal->min_loc, 2);
	ft_putstr_fd("\nmax: ", 2);
	ft_putnbr_fd(s_anal->max, 2);
	ft_putstr_fd("\nmax_loc: ", 2);
	ft_putnbr_fd(s_anal->max_loc, 2);
	ft_putstr_fd("\nruns: ", 2);
	ft_putnbr_fd(s_anal->runs, 2);
	ft_putstr_fd("\nsize: ", 2);
	ft_putnbr_fd(s_anal->size, 2);
	ft_putstr_fd("\n", 2);
}

static int	ft_to_do_when_sorted(t_push_swap_data *d, t_sort_anal *s_anal)
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
			psd_apply_cmd_xn(d, rrr, d->stack_a->size- min_loc, 1);
	}
	return (ret);
}

static void	ft_apply_sorting(t_push_swap_data *d)
{
	t_sort_anal	*s_anal;

	s_anal = ft_sort_anal(sd_asc, d->stack_a->dll, d->stack_a->size);
	if (s_anal)
		if (ft_to_do_when_sorted(d, s_anal))
			return ;
	if (d->stack_a->size == 2)
		ft_sort_2_a_b(d);
	else if (d->stack_a->size == 3)
		ft_sort_3_a(d);
	else if (d->stack_a->size == 4 || d->stack_a->size == 5)
		ft_sort_4_5_a(d);
	else
		ft_sort_gt_5(d);
}

static void	ft_process_valid_data(t_push_swap_data *d)
{
	d->stack_a = ft_fill_stack_with_tab(d->stack_a, \
					d->tab, d->sorted, d->size);
	free_x((void **)&d->sorted);
	free_x((void **)&d->tab);
	ft_apply_sorting(d);
	d->cmd_list = ft_lstreverse(&d->cmd_list);
	ft_putstackcmdlst_fd(d->cmd_list, 1);
}

int	main(int argc, char const *argv[])
{
	t_push_swap_data	*d;

	d = psd_constructor();
	if (! d)
		ft_log_err_exit ("push swap data constructor failed\n", NULL);
	d->tab = ft_take_arguments(&d, argc, argv);
	if (d->tab)
	{
		d->sorted = ft_clone_int_tab(d->tab, d->size);
		if (! d->sorted)
			ft_log_err_exit("malloc failed when alocating memory\n", &d);
		ft_sort_int_tab(d->sorted, d->size);
		if (ft_check_duplicated(d->sorted, d->size))
			ft_process_valid_data(d);
		psd_dispose(&d);
	}
	return (0);
}
