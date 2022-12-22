/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack_with_arg.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:18:51 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/22 13:09:47 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static int	ft_equal_int(unsigned int i, int el, int arg)
{
	(void)i;
	return (el == arg);
}

static t_ps_stack	*ft_init_ps_stack(t_ps_stack *dst)
{
	t_ps_stack	*stack;

	if (! dst)
		stack = pss_constructor();
	else
		stack = dst;
	return (stack);
}

t_ps_stack	*ft_fill_stack_with_tab(t_ps_stack	*dst, int *tab, \
				int *sorted, size_t size)
{
	t_ps_stack	*stack;
	t_dllist	*nn;
	size_t		i;

	stack = ft_init_ps_stack(dst);
	if (! tab || ! sorted || size == 0 || ! stack)
		return (NULL);
	i = 0;
	while (i < size)
	{
		nn = ft_new_stack_el(tab[i], \
				ft_find_first_int(sorted, size, &ft_equal_int, tab[i]));
		if (nn)
			pss_add_back(stack, nn);
		else
		{
			pss_clear(stack);
			return (NULL);
		}
		i++;
	}
	return (stack);
}
