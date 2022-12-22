/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:05:15 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/22 15:56:20 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static void	ft_print_header(size_t sa, size_t sb)
{
	ft_putstr_fd("STACK A: size = ", 1);
	ft_putnbr_fd(sa, 1);
	ft_putstr_fd("\t\tSTACK B: size = ", 1);
	ft_putnbr_fd(sb, 1);
	ft_putstr_fd("\n", 1);
}

static void	ft_print_el_sep(void *content, char *sep)
{
	t_stack_el	*el;

	el = content;
	ft_putstr_fd("nbr: ", 1);
	ft_putnbr_fd(el->nbr, 1);
	ft_putstr_fd(", \torder: ", 1);
	ft_putnbr_fd(el->order, 1);
	ft_putstr_fd(sep, 1);
}

static void	ft_print_stacks_line(t_push_swap_data *d, size_t i)
{
	static t_ps_stack	*pss_a;
	static t_ps_stack	*pss_b;
	static t_dllist		*pss_a_node;
	static t_dllist		*pss_b_node;

	if (i == 0)
	{
		pss_a = d->stack_a;
		pss_a_node = pss_a->dll;
		pss_b = d->stack_b;
		pss_b_node = pss_b->dll;
	}
	if (i < pss_a->size)
	{
		ft_print_el_sep(pss_a_node->content, "\t");
		pss_a_node = pss_a_node->next;
	}
	else
		ft_putstr_fd("\t\t\t\t", 1);
	if (i < pss_b->size)
	{
		ft_print_el_sep(pss_b_node->content, "");
		pss_b_node = pss_b_node->next;
	}
	ft_putstr_fd("\n", 1);
}

void	ft_print_stacks(t_push_swap_data *d, char *sep)
{
	t_ps_stack	*pss_a;
	t_ps_stack	*pss_b;
	size_t		max_size;
	size_t		i;

	if (! d)
		return ;
	pss_a = d->stack_a;
	pss_b = d->stack_b;
	if (! pss_a || ! pss_b)
		return ;
	max_size = pss_a->size;
	if (pss_b->size > max_size)
		max_size = pss_b->size;
	i = 0;
	ft_print_header(pss_a->size, pss_b->size);
	while (i < max_size)
		ft_print_stacks_line(d, i++);
	ft_putstr_fd(sep, 1);
}
