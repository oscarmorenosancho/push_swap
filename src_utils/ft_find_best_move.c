/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_best_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:00:13 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/02 14:06:02 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static size_t	ft_init_info(int a_b, t_push_swap_data *d, \
					t_dllist **s_dllist, t_dllist **d_dllist)
{
	if (a_b)
	{
		*s_dllist = d->stack_a->dll;
		*d_dllist = d->stack_b->dll;
		return (d->stack_b->size);
	}
	*s_dllist = d->stack_b->dll;
	*d_dllist = d->stack_a->dll;
	return (d->stack_a->size);
}

static void	ft_find_best_move_d(t_move_desc *mv_desc, \
			t_push_swap_data *d, int *range)
{
	t_dllist	*s_dllist;
	t_dllist	*d_dllist;
	t_dllist	*fst;
	t_ips_opt	ips_opt;
	size_t		d_size;

	d_size = ft_init_info (mv_desc->a_b, d, &s_dllist, &d_dllist);
	ips_opt.sort_dir = sd_asc;
	if (mv_desc->a_b)
		ips_opt.sort_dir = sd_desc;
	mv_desc->s_loc = -1;
	fst = ft_dllstfindfirstinrange(&mv_desc->s_loc, s_dllist, range);
	if (mv_desc->s_loc != -1)
	{
		ips_opt.order = ((t_stack_el *)(fst->content))->order;
		if (d_size > 1)
			ft_dllstfindfirstinsertloc(&mv_desc->d_loc, d_dllist, &ips_opt);
		else
			mv_desc->d_loc = 0;
	}
}

static void	ft_find_best_move_r(t_move_desc *mv_desc, \
			t_push_swap_data *d, int *range)
{
	t_dllist	*s_dllist;
	t_dllist	*d_dllist;
	t_dllist	*fst;
	t_ips_opt	ips_opt;
	size_t		d_size;

	d_size = ft_init_info (mv_desc->a_b, d, &s_dllist, &d_dllist);
	ips_opt.sort_dir = sd_asc;
	if (mv_desc->a_b)
		ips_opt.sort_dir = sd_desc;
	mv_desc->s_loc = -1;
	fst = ft_dllstfindfirstinrangerev(&mv_desc->s_loc, s_dllist, range);
	if (mv_desc->s_loc != -1)
	{
		ips_opt.order = ((t_stack_el *)(fst->content))->order;
		if (d_size > 1)
			ft_dllstfindfirstinsertlocrev(&mv_desc->d_loc, d_dllist, \
				&ips_opt);
		else
			mv_desc->d_loc = 0;
	}
}

void	ft_find_best_move(t_move_desc *mv_desc, \
			t_push_swap_data *d, int *range, int a_b)
{
	t_move_desc	mv_desc_d;
	t_move_desc	mv_desc_r;
	int			max_d;
	int			max_r;

	mv_desc_d.a_b = a_b;
	mv_desc_r.a_b = a_b;
	mv_desc_d.s_d_r = 0;
	mv_desc_r.s_d_r = 1;
	mv_desc_d.d_d_r = 0;
	mv_desc_r.d_d_r = 1;
	ft_find_best_move_d(&mv_desc_d, d, range);
	ft_find_best_move_r(&mv_desc_r, d, range);
	max_d = ft_max(mv_desc_d.s_loc, mv_desc_d.d_loc);
	max_r = ft_max(mv_desc_r.s_loc, mv_desc_r.d_loc);
	if (max_d < max_r)
		*mv_desc = mv_desc_d;
	else
		*mv_desc = mv_desc_r;
}
