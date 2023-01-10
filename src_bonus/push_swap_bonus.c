/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:14:08 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/10 15:53:48 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_process_valid_data(t_push_swap_data *d)
{
	d->stack_a = ft_fill_stack_with_tab(d->stack_a, \
					d->tab, d->sorted, d->size);
	free_x((void **)&d->sorted);
	free_x((void **)&d->tab);
	ft_read_n_play_cmd_list_fd(d, 0);
	if (ft_check_stack_ordered(d->stack_a->dll) && d->stack_b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
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
