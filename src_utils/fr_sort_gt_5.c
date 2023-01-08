/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_sort_gt_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:43:07 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/08 17:09:16 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	ft_sort_gt_5(t_push_swap_data *d)
{
	int			size;
	int			scale;
	int			chunk_size;
	t_sort_anal	*s_anal;

	size = d->stack_a->size;
	if (size < 11)
		chunk_size = 1;
	else
		chunk_size = size / 11;
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
	ft_move_eq_chuncks_to_a(d, chunk_size, 0);
	s_anal = ft_sort_anal(sd_asc, d->stack_a->dll, d->stack_a->size);
	if (s_anal)
		ft_to_do_when_sorted(d, s_anal);
}
