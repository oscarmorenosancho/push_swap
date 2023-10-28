/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_class2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:35:53 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 23:10:49 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_utils.h>

t_dllist	*pss_extract(t_ps_stack *pss)
{
	t_dllist	*node;

	if (! pss)
		return (NULL);
	node = ft_dllst_extract(&pss->dll);
	if (node)
		pss->size--;
	return (node);
}

void	pss_push(t_ps_stack *dst, t_ps_stack *src)
{
	if (! dst || !src)
		return ;
	if (src->dll)
	{
		ft_dllst_push(&dst->dll, &src->dll);
		dst->size++;
		src->size--;
	}
}

void	pss_swap(t_ps_stack *pss)
{
	if (! pss)
		return ;
	if (pss->dll && pss->size > 1)
		ft_dllst_swap(&pss->dll);
}

void	pss_rotate(t_ps_stack *pss)
{
	if (! pss)
		return ;
	if (pss->dll && pss->size > 1)
		ft_dllst_rotate(&pss->dll);
}

void	pss_revrotate(t_ps_stack *pss)
{
	if (! pss)
		return ;
	if (pss->dll && pss->size > 1)
		ft_dllst_revrotate(&pss->dll);
}
