/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_sort_gt_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:43:07 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 23:10:48 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_utils.h>

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
	int			chunk_size;
	t_sort_anal	*s_anal;

	size = d->stack_a->size;
	chunk_size = ft_eval_chunk_size (size, 4);
	ft_move_shr_chuncks_to_b(d, chunk_size, 1);
	chunk_size = ft_eval_chunk_size (size, 20);
	ft_move_chuncks_to_a(d, chunk_size, 0);
	s_anal = ft_sort_anal(sd_asc, d->stack_a->dll, d->stack_a->size);
	if (s_anal)
		ft_to_do_when_sorted(d, s_anal);
}
