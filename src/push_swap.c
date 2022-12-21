/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:14:08 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/21 15:56:38 by omoreno-         ###   ########.fr       */
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

static int	ft_equal_int(unsigned int i, int el, int arg)
{
	(void)i;
	return (el == arg);
}

static t_dllist	*ft_fill_stack_with_arg(int *tab, int *sorted, size_t size)
{
	t_dllist	*dll;
	t_dllist	*nn;
	size_t		i;
	int			loc;

	dll = NULL;
	if (! tab || ! sorted || size == 0)
		return (NULL);
	i = 0;
	while (i < size)
	{
		loc = ft_find_first_int(sorted, size, &ft_equal_int, tab[i]);
		nn = ft_new_stack_el(tab[i], loc);
		if (nn)
			ft_dllstadd_back(&dll, nn);
		else
		{
			ft_dllstclear(&dll, &free);
			return (NULL);
		}
		i++;
	}
	return (dll);
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
	t_prog_data	d;
	int			loc;
	t_dllist	*node;
	int			range[2];

	d.tab = ft_take_arguments(&d.size, argc, argv);
	if (d.tab)
	{
		ft_putstr_fd("tab\n", 1);
		ft_tabiteri(d.tab, d.size, &ft_print_int);
		d.sorted = ft_clone_int_tab(d.tab, d.size);
		if (! d.sorted)
			ft_log_err_exit("malloc failed when alocating memory\n", &d.tab);
		ft_sort_int_tab(d.sorted, d.size);
		if (ft_check_duplicated(d.sorted, d.size))
		{
			d.stack_a = ft_fill_stack_with_arg(d.tab, d.sorted, d.size);
			ft_putstr_fd("STACK A\n", 1);
			ft_dllstiter(d.stack_a, &ft_print_el);
			ft_putstr_fd("STACK B\n", 1);
			ft_dllstiter(d.stack_b, &ft_print_el);
			ft_putstr_fd("FIRST IN RANGE 20, 900\n", 1);
			range[0] = 20;
			range[1] = 900;
			node = ft_dllstfindfirstinrange(&loc, d.stack_a, range);
			ft_putnbr_fd(loc, 1);
			if (loc != -1)
			{
				ft_putstr_fd("\n node order :", 1);
				ft_putnbr_fd(((t_stack_el *)node->content)->order, 1);
				ft_putstr_fd(" node nbr : ", 1);
				ft_putnbr_fd(((t_stack_el *)node->content)->nbr, 1);
				ft_putstr_fd("\n", 1);
			}
			else
				ft_putstr_fd("\nnot found\n", 1);
		}
		free_x((void **)&d.sorted);
		free_x((void **)&d.tab);
		ft_dllstclear(&d.stack_a, &free);
		ft_dllstclear(&d.stack_b, &free);
	}
	return (0);
}
