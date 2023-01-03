/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_sort_gt_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:43:07 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/03 18:23:39 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	ft_sort_gt_5(t_push_swap_data *d)
{
	int	size;
	int	scale;
	int	chunk_size;

	size = d->stack_a->size;
	chunk_size = size / 11;
	scale = 1;
	ft_move_eq_chuncks_to_b(d, chunk_size, 1);
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
	ft_move_eq_chuncks_to_a(d, 1, 1);
}
