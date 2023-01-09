/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_sort_gt_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:43:07 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/09 14:05:06 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static int	ft_eval_chunk_size(int size, int count)
{
	if (size < count)
		return (1);
	else
		return (size / count);
}

void	ft_sort_gt_5(t_push_swap_data *d)
{
	int			size;
	int			scale;
	int			chunk_size;
	t_sort_anal	*s_anal;

	size = d->stack_a->size;
	chunk_size = ft_eval_chunk_size (size, 4);
	scale = 1;
	ft_move_eq_chuncks_to_b(d, chunk_size, 1);
	//ft_expel_unsorted(d);
	//psd_apply_cmd_xn(d, pb, d->stack_a->size, 1);
	scale <<= 1;
	/*if (d->stack_a->size > 0)
		psd_apply_cmd_xn(d, pb, d->stack_a->size, 1);
	while (chunk_size > 10 && 0)
	{
		ft_move_eq_chuncks_to_a(d, chunk_size, chunk_size < 16);
		chunk_size /= 2;
		ft_move_eq_chuncks_to_b(d, chunk_size, chunk_size < 10);
		chunk_size /= 2;
	}*/
	chunk_size = ft_eval_chunk_size (size, 20);
	ft_move_eq_chuncks_to_a(d, chunk_size, 0);
	//ft_move_close_chuncks_to_a(d, 0);
	s_anal = ft_sort_anal(sd_asc, d->stack_a->dll, d->stack_a->size);
	if (s_anal)
		ft_to_do_when_sorted(d, s_anal);
}
