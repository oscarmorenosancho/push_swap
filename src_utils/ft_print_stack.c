/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:38:16 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/22 15:04:23 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

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
