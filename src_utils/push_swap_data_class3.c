/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_data_class3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:10:32 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/08 17:18:41 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	psd_apply_cmd_a(t_push_swap_data *d, t_move_desc *mv_desc, int yet_done)
{
	t_stack_cmd	sc;
	int			rep;

	if (mv_desc->a_b)
	{
		rep = mv_desc->s_loc;
		if (mv_desc->s_d_r)
			sc = rra;
		else
			sc = ra;
	}
	else
	{
		rep = mv_desc->d_loc;
		if (mv_desc->d_d_r)
			sc = rra;
		else
			sc = ra;
	}
	if (rep - yet_done > 0)
		psd_apply_cmd_xn(d, sc, rep - yet_done, 1);
}

void	psd_apply_cmd_b(t_push_swap_data *d, t_move_desc *mv_desc, int yet_done)
{
	t_stack_cmd	sc;
	int			rep;

	if (! mv_desc->a_b)
	{
		rep = mv_desc->s_loc;
		if (mv_desc->s_d_r)
			sc = rrb;
		else
			sc = rb;
	}
	else
	{
		rep = mv_desc->d_loc;
		if (mv_desc->d_d_r)
			sc = rrb;
		else
			sc = rb;
	}
	if (rep - yet_done > 0)
		psd_apply_cmd_xn(d, sc, rep - yet_done, 1);
}

static void	psd_apply_coherent_rots_sim(t_push_swap_data *d, \
				t_move_desc *mv_desc)
{
	int			rep;

	rep = ft_min(mv_desc->s_loc, mv_desc->d_loc);
	if (rep < 1)
		return ;
	if (mv_desc->s_d_r)
		psd_apply_cmd_xn(d, rrr, rep, 1);
	else
		psd_apply_cmd_xn(d, rr, rep, 1);
}

static void	psd_apply_coherent_rots_rest(t_push_swap_data *d, \
				t_move_desc *mv_desc)
{
	int			yet_done;

	if (mv_desc->s_loc == mv_desc->d_loc)
		return ;
	yet_done = ft_min(mv_desc->s_loc, mv_desc->d_loc);
	if ((mv_desc->s_loc > mv_desc->d_loc && mv_desc->a_b) || \
		(mv_desc->s_loc < mv_desc->d_loc && !mv_desc->a_b))
		psd_apply_cmd_a(d, mv_desc, yet_done);
	else
		psd_apply_cmd_b(d, mv_desc, yet_done);
}

void	psd_apply_move(t_push_swap_data *d, t_move_desc *mv_desc)
{
	if (mv_desc->s_d_r == mv_desc->d_d_r && ! mv_desc->not_dest)
	{
		psd_apply_coherent_rots_sim(d, mv_desc);
		psd_apply_coherent_rots_rest(d, mv_desc);
	}
	else
	{
		if (mv_desc->a_b || ! mv_desc->not_dest)
			psd_apply_cmd_a(d, mv_desc, 0);
		if (! mv_desc->a_b || ! mv_desc->not_dest)
			psd_apply_cmd_b(d, mv_desc, 0);
	}
	if (mv_desc->a_b)
		psd_apply_cmd(d, pb, 1);
	else
		psd_apply_cmd(d, pa, 1);
}
