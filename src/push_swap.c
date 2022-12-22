/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:14:08 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/22 17:08:45 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_int(unsigned int i, int *tab)
{
	(void)i;
	if (tab)
	{
		ft_putnbr_fd(*tab, 1);
		ft_putchar_fd('\n', 1);
	}
	else
		ft_log_error("table or element does not exist\n");
}

static void	ft_process_valid_data(t_push_swap_data *d)
{
	d->stack_a = ft_fill_stack_with_tab(d->stack_a, \
					d->tab, d->sorted, d->size);
	ft_print_stacks(d, "-----------\t-----------\t-----------\t-----------\n");
	/*pss_push(d->stack_b, d->stack_a);
	pss_push(d->stack_b, d->stack_a);
	pss_push(d->stack_b, d->stack_a);
	pss_push(d->stack_b, d->stack_a);
	pss_rotate(d->stack_a);
	pss_rotate(d->stack_a);
	pss_push(d->stack_b, d->stack_a);
	pss_swap(d->stack_a);
	pss_push(d->stack_b, d->stack_a);
	pss_rotate(d->stack_a);
	pss_revrotate(d->stack_a);*/
	psd_apply_cmd(d, pb);
	psd_apply_cmd(d, pb);
	psd_apply_cmd(d, ss);
	ft_putstr_fd("\n====\n", 1);
	ft_print_stacks(d, "----------\n");
	if (ft_check_stack_ordered(d->stack_a->dll))
		ft_putstr_fd("stack A is ordered\n", 1);
	else
		ft_putstr_fd("stack A is NOT ordered\n", 1);
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
		ft_putstr_fd("tab\n", 1);
		ft_tabiteri(d->tab, d->size, &ft_print_int);
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
