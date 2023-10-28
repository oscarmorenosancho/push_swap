/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:14:08 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 23:52:18 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	ft_print_el(void *content)
{
	t_stack_el	*el;

	el = content;
	ft_putstr_fd("nbr: ", 1);
	ft_putnbr_fd(el->nbr, 1);
	ft_putstr_fd(", \torder: ", 1);
	ft_putnbr_fd(el->order, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_print_stack(t_ps_stack *stack, char name, char *sep)
{
	ft_putstr_fd("STACK ", 1);
	ft_putchar_fd(name, 1);
	ft_putstr_fd(": size: ", 1);
	ft_putnbr_fd(stack->size, 1);
	ft_putstr_fd("\n", 1);
	ft_dllstiter(stack->dll, &ft_print_el);
	ft_putstr_fd(sep, 1);
}

static void	ft_process_valid_data(t_push_swap_data *d)
{
	d->stack_a = ft_fill_stack_with_tab(d->stack_a, \
					d->tab, d->sorted, d->size);
	free_x((void **)&d->sorted);
	free_x((void **)&d->tab);
	ft_read_n_play_cmd_list_fd(d, 0);
	ft_print_stack(d->stack_a, 'A', "|");
	ft_print_stack(d->stack_b, 'B', "|");
	if (ft_check_stack_ordered(d->stack_a))
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
