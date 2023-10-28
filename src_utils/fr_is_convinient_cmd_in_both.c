/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_is_convinient_cmd_in_both.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:51:43 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 23:10:52 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_utils.h>

int	fr_is_convinient_rr(t_push_swap_data *psd, t_stack_cmd sc)
{
	t_dllist	*head;
	t_stack_el	*head_el;
	t_stack_el	*alt_el;

	if (sc == ra && psd->stack_b->size > 1)
	{
		head = psd->stack_b->dll;
		head_el = head->content;
		alt_el = (head->next)->content;
		return (head_el->order < alt_el->order);
	}
	if (sc == rb && psd->stack_a->size > 1)
	{
		head = psd->stack_a->dll;
		head_el = head->content;
		alt_el = (head->next)->content;
		return (head_el->order > alt_el->order);
	}
	return (0);
}

int	fr_is_convinient_rrr(t_push_swap_data *psd, t_stack_cmd sc)
{
	t_dllist	*head;
	t_stack_el	*head_el;
	t_stack_el	*alt_el;

	if (sc == rra && psd->stack_b->size > 1)
	{
		head = psd->stack_b->dll;
		head_el = head->content;
		alt_el = (head->prev)->content;
		return (head_el->order < alt_el->order);
	}
	if (sc == rrb && psd->stack_a->size > 1)
	{
		head = psd->stack_a->dll;
		head_el = head->content;
		alt_el = (head->prev)->content;
		return (head_el->order > alt_el->order);
	}
	return (0);
}

int	fr_is_convinient_ss(t_push_swap_data *psd, t_stack_cmd sc)
{
	t_dllist	*head;
	t_stack_el	*head_el;
	t_stack_el	*alt_el;

	if (sc == sa && psd->stack_b->size > 1)
	{
		head = psd->stack_b->dll;
		head_el = head->content;
		alt_el = (head->next)->content;
		return (head_el->order < alt_el->order);
	}
	if (sc == sb && psd->stack_a->size > 1)
	{
		head = psd->stack_a->dll;
		head_el = head->content;
		alt_el = (head->next)->content;
		return (head_el->order > alt_el->order);
	}
	return (0);
}

int	fr_is_convinient_cmd_in_both(t_push_swap_data *psd, t_stack_cmd sc)
{
	if (sc == ra || sc == rb)
		return (fr_is_convinient_rr(psd, sc));
	if (sc == rra || sc == rrb)
		return (fr_is_convinient_rrr(psd, sc));
	if (sc == sa || sc == sb)
		return (fr_is_convinient_ss(psd, sc));
	return (0);
}
