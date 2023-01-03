/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_chunck_to_s.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:16:28 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/03 18:00:10 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	ft_find_closest_a_mv_b(t_push_swap_data *d, int *range, \
					int dis_dbl, int half_stack_size)
{
	t_dllist	*fst_d;
	t_dllist	*fst_r;
	int			loc_d;
	int			loc_r;

	loc_d = half_stack_size;
	loc_r = half_stack_size;
	fst_d = ft_dllstfindfirstinrange(&loc_d, d->stack_a->dll, range);
	fst_r = ft_dllstfindfirstinrangerev(&loc_r, d->stack_a->dll, range);
	if (dis_dbl)
	{
		if (loc_d != -1 && (loc_r == -1 || loc_d < loc_r))
			ft_apply_c1xn_n_c2_dd(d, ra, loc_d, pb);
		else if (loc_r != -1)
			ft_apply_c1xn_n_c2_dd(d, rra, loc_r, pb);
	}
	else
	{
		if (loc_d != -1 && (loc_r == -1 || loc_d < loc_r))
			ft_apply_c1xn_n_c2(d, ra, loc_d, pb);
		else if (loc_r != -1)
			ft_apply_c1xn_n_c2(d, rra, loc_r, pb);
	}
}

void	ft_find_closest_b_mv_a(t_push_swap_data *d, int *range, \
					int dis_dbl, int half_stack_size)
{
	t_dllist	*fst_d;
	t_dllist	*fst_r;
	int			loc_d;
	int			loc_r;

	loc_d = half_stack_size;
	loc_r = half_stack_size;
	fst_d = ft_dllstfindfirstinrange(&loc_d, d->stack_b->dll, range);
	fst_r = ft_dllstfindfirstinrangerev(&loc_r, d->stack_b->dll, range);
	if (dis_dbl)
	{
		if (loc_d != -1 && (loc_r == -1 || loc_d < loc_r))
			ft_apply_c1xn_n_c2_dd(d, rb, loc_d, pa);
		else if (loc_r != -1)
			ft_apply_c1xn_n_c2_dd(d, rrb, loc_r, pa);
	}
	else
	{
		if (loc_d != -1 && (loc_r == -1 || loc_d < loc_r))
			ft_apply_c1xn_n_c2(d, rb, loc_d, pa);
		else if (loc_r != -1)
			ft_apply_c1xn_n_c2(d, rrb, loc_r, pa);
	}
}

void	ft_move_chunck_to_b(t_push_swap_data *d, int *range, int dis_dbl)
{
	int			i;
	int			chunck_size;
	int			half_stack_size;
	t_move_desc	mv_desc;

	(void)dis_dbl;
	chunck_size = range[1] - range[0] + 1;
	half_stack_size = (d->stack_a->size + 1) / 2;
	i = 0;
	while (i < chunck_size)
	{
		ft_find_best_move(&mv_desc, d, range, 1);
		psd_apply_move(d, &mv_desc);
		i++;
	}
}

void	ft_move_chunck_to_a(t_push_swap_data *d, int *range, int dis_dbl)
{
	int			i;
	int			chunck_size;
	int			half_stack_size;
	t_move_desc	mv_desc;

	(void)dis_dbl;
	chunck_size = range[1] - range[0] + 1;
	half_stack_size = (d->stack_b->size + 1) / 2;
	i = 0;
	while (i < chunck_size)
	{
		ft_find_best_move(&mv_desc, d, range, 0);
		psd_apply_move(d, &mv_desc);
		i++;
	}
}
