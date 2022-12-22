/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:14:08 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/22 13:22:05 by omoreno-         ###   ########.fr       */
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

static void	ft_print_el(void *content)
{
	t_stack_el	*el;

	el = content;
	ft_putstr_fd("nbr: ", 1);
	ft_putnbr_fd(el->nbr, 1);
	ft_putstr_fd(", order: ", 1);
	ft_putnbr_fd(el->order, 1);
	ft_putchar_fd('\n', 1);
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
		{
			d->stack_a = ft_fill_stack_with_tab(d->stack_a, \
							d->tab, d->sorted, d->size);
			ft_putstr_fd("STACK A\n", 1);
			ft_dllstiter(d->stack_a->dll, &ft_print_el);
			ft_putstr_fd("STACK B\n", 1);
			ft_dllstiter(d->stack_b->dll, &ft_print_el);
			if (ft_check_stack_ordered(d->stack_a->dll))
				ft_putstr_fd("stack is ordered\n", 1);
			else
				ft_putstr_fd("stack is NOT ordered\n", 1);
		}
		psd_dispose(&d);
	}
	return (0);
}
