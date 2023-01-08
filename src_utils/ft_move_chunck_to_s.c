/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_chunck_to_s.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:16:28 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/08 16:47:57 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	ft_move_chunck_to_b(t_push_swap_data *d, int *range, int not_dest)
{
	int			i;
	int			chunck_size;
	int			half_stack_size;
	t_move_desc	mv_desc;

	chunck_size = range[1] - range[0] + 1;
	half_stack_size = (d->stack_a->size + 1) / 2;
	i = 0;
	while (i < chunck_size)
	{
		ft_find_best_move(&mv_desc, d, range, 1);
		mv_desc.not_dest = not_dest;
		psd_apply_move(d, &mv_desc);
		i++;
	}
}

void	ft_move_chunck_to_a(t_push_swap_data *d, int *range, int not_dest)
{
	int			i;
	int			chunck_size;
	int			half_stack_size;
	t_move_desc	mv_desc;

	chunck_size = range[1] - range[0] + 1;
	half_stack_size = (d->stack_b->size + 1) / 2;
	i = 0;
	while (i < chunck_size)
	{
		ft_find_best_move(&mv_desc, d, range, 0);
		mv_desc.not_dest = not_dest;
		psd_apply_move(d, &mv_desc);
		i++;
	}
}
