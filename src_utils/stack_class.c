/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_class.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:16:18 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 23:10:49 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_utils.h>

t_ps_stack	*pss_constructor(void)
{
	t_ps_stack	*pss;

	pss = malloc(sizeof(t_ps_stack));
	pss->size = 0;
	pss->dll = NULL;
	return (pss);
}

void	pss_clear(t_ps_stack *pss)
{
	if (! pss)
		return ;
	ft_dllstclear(&pss->dll, &free);
	pss->size = 0;
}

void	pss_dispose(t_ps_stack **pss)
{
	if (! pss)
		return ;
	pss_clear(*pss);
	(*pss)->size = 0;
	free_x((void **)pss);
}

void	pss_add_front(t_ps_stack *pss, t_dllist *nn)
{
	if (! pss)
		return ;
	ft_dllstadd_front(&pss->dll, nn);
	pss->size++;
}

void	pss_add_back(t_ps_stack *pss, t_dllist *nn)
{
	if (! pss)
		return ;
	ft_dllstadd_back(&pss->dll, nn);
	pss->size++;
}
