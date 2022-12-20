/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:14:08 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/20 17:13:12 by omoreno-         ###   ########.fr       */
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

	i = 0;
	dll = NULL;
	if (! tab || ! sorted || size < 1)
		return (NULL);
	while (i < size)
	{
		loc = ft_find_first_int(sorted, size, &ft_equal_int, tab[i]);
		nn = ft_new_stack_el(tab[i], loc);
		if (nn)
			ft_dllstadd_front(&dll, nn);
		else
		{
			ft_dllstclear(&dll, &free);
			return (NULL);
		}
		i++;
	}
	return (dll);
}

int	main(int argc, char const *argv[])
{
	int			*tab;
	int			*sorted;
	size_t		size;
	t_dllist	*stack_a;
	void		*fnt;

	fnt = ft_fill_stack_with_arg;
	tab = ft_take_arguments(&size, argc, argv);
	if (tab)
	{
		ft_sort_int_tab(tab, size);
		sorted = ft_clone_int_tab(tab, size);
		if (! sorted)
			ft_log_err_exit("malloc failed when alocating memory\n", &tab);
		if (ft_check_duplicated(sorted, size))
		{
			ft_tabiteri(sorted, size, &ft_print_int);
			stack_a = ft_fill_stack_with_arg(tab, sorted, size);
		}
		free_x((void **)&sorted);
		free_x((void **)&tab);
		ft_dllstclear(&stack_a, &free);
	}
	return (0);
}
