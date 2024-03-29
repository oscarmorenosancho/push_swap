/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:14:08 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 23:45:02 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
	}
	psd_dispose(&d);
	return (0);
}
