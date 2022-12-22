/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_data_class.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:34:44 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/22 12:46:20 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

t_push_swap_data	*psd_constructor(void)
{
	t_push_swap_data	*psd;

	psd = ft_calloc(1, sizeof(t_push_swap_data));
	psd->stack_a = pss_constructor();
	psd->stack_b = pss_constructor();
	return (psd);
}

void	psd_dispose(t_push_swap_data **psd)
{
	t_push_swap_data	*d;

	if (!psd)
		return ;
	d = *psd;
	free_x((void **)&d->sorted);
	free_x((void **)&d->tab);
	pss_dispose(&d->stack_a);
	pss_dispose(&d->stack_b);
}
