/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_best_move2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:28:16 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/09 12:13:17 by omoreno-         ###   ########.fr       */
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

static void	ft_init_ips_opt(t_ips_opt *ips_opt, int a_b, int size)
{
	ips_opt->size = size;
	ips_opt->sort_dir = sd_asc;
	if (a_b)
		ips_opt->sort_dir = sd_desc;
}

static void	ft_reconsider_best(t_move_desc *mv_desc, size_t d_size)
{
	int	contrary_loc;
	int	max_alt;

	contrary_loc = d_size - mv_desc->d_loc;
	max_alt = contrary_loc + mv_desc->s_loc;
	mv_desc->max = ft_max(mv_desc->s_loc, mv_desc->d_loc);
	if (max_alt < mv_desc->max)
	{
		mv_desc->d_d_r = (1 - mv_desc->d_d_r);
		mv_desc->d_loc = contrary_loc;
		mv_desc->max = max_alt;
	}
}

void	ft_find_best_move_d(t_move_desc *mv_desc, \
			t_push_swap_data *d, int *range)
{
	t_dllist	*s_dllist;
	t_dllist	*d_dllist;
	t_dllist	*fst;
	t_ips_opt	ips_opt;
	size_t		d_size;

	mv_desc->s_d_r = 0;
	mv_desc->d_d_r = 0;
	d_size = ft_init_info (mv_desc->a_b, d, &s_dllist, &d_dllist);
	ft_init_ips_opt(&ips_opt, mv_desc->a_b, d->size);
	mv_desc->s_loc = ft_max(d->stack_a->size, d->stack_b->size);
	mv_desc->d_loc = ft_max(d->stack_a->size, d->stack_b->size);
	fst = ft_dllstfindfirstinrange(&mv_desc->s_loc, s_dllist, range);
	if (mv_desc->s_loc != -1)
	{
		ips_opt.order = ((t_stack_el *)(fst->content))->order;
		if (d_size > 1 && ! mv_desc->not_dest)
			ft_dllstfindfirstinsertloc(&mv_desc->d_loc, d_dllist, &ips_opt);
		else
			mv_desc->d_loc = 0;
		ft_reconsider_best(mv_desc, d_size);
	}
	else
		mv_desc->max = ft_max(d->stack_a->size, d->stack_b->size);
}

void	ft_find_best_move_r(t_move_desc *mv_desc, \
			t_push_swap_data *d, int *range)
{
	t_dllist	*s_dllist;
	t_dllist	*d_dllist;
	t_dllist	*fst;
	t_ips_opt	ips_opt;
	size_t		d_size;

	mv_desc->s_d_r = 1;
	mv_desc->d_d_r = 1;
	d_size = ft_init_info (mv_desc->a_b, d, &s_dllist, &d_dllist);
	ft_init_ips_opt(&ips_opt, mv_desc->a_b, d->size);
	mv_desc->s_loc = ft_max(d->stack_a->size, d->stack_b->size);
	mv_desc->d_loc = ft_max(d->stack_a->size, d->stack_b->size);
	fst = ft_dllstfindfirstinrangerev(&mv_desc->s_loc, s_dllist, range);
	if (mv_desc->s_loc != -1)
	{
		ips_opt.order = ((t_stack_el *)(fst->content))->order;
		if (d_size > 1 && ! mv_desc->not_dest)
			ft_dllstfindfirstinsertlocrev(&mv_desc->d_loc, d_dllist, \
				&ips_opt);
		else
			mv_desc->d_loc = 0;
		ft_reconsider_best(mv_desc, d_size);
	}
	else
		mv_desc->max = ft_max(d->stack_a->size, d->stack_b->size);
}
