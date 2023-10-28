/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstfindfirstinsertloc.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:17:24 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 21:58:39 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static int	ft_is_insert_pos(unsigned int i, t_dllist *node, void *arg)
{
	int			is_disc;
	int			order;
	t_ips_opt	*ips_opt;
	t_stack_el	*el;
	t_stack_el	*prev_el;

	(void)i;
	ips_opt = arg;
	order = ips_opt->order;
	el = node->content;
	prev_el = node->prev->content;
	is_disc = ((ips_opt->sort_dir == sd_desc && prev_el->order < el->order) \
				|| (ips_opt->sort_dir == sd_asc && prev_el->order > el->order));
	if (is_disc && ips_opt->sort_dir == sd_asc)
		return ((order > prev_el->order) || (order < el->order));
	if (is_disc && ips_opt->sort_dir == sd_desc)
		return ((order < prev_el->order) || (order > el->order));
	if (! is_disc && ips_opt->sort_dir == sd_asc)
		return ((prev_el->order < order) && (order < el->order));
	if (! is_disc && ips_opt->sort_dir == sd_desc)
		return ((prev_el->order > order) && (order > el->order));
	return (0);
}

t_dllist	*ft_dllstfindfirstinsertloc(int *loc, t_dllist *lst, \
				t_ips_opt *ips_opt)
{
	t_dllist	*ret;

	ret = ft_dllstfindfirst(loc, lst, &ft_is_insert_pos, ips_opt);
	return (ret);
}

t_dllist	*ft_dllstfindfirstinsertlocrev(int *loc, t_dllist *lst, \
				t_ips_opt *ips_opt)
{
	t_dllist	*ret;

	ret = ft_dllstfindfirstrev(loc, lst, &ft_is_insert_pos, ips_opt);
	return (ret);
}
