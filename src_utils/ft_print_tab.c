/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:56:14 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/23 14:59:41 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

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

void	ft_print_tab(int *tab, size_t size)
{
	ft_putstr_fd("tab\n", 1);
	ft_tabiteri(tab, size, &ft_print_int);
	ft_putstr_fd("------\n", 1);
}
