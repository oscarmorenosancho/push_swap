/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_best_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:00:13 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 23:10:49 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_utils.h>

void	ft_find_best_move(t_move_desc *mv_desc, \
			t_push_swap_data *d, int *range)
{
	t_move_desc	mv_desc_d;
	t_move_desc	mv_desc_r;

	mv_desc_d = *mv_desc;
	mv_desc_r = *mv_desc;
	ft_find_best_move_d(&mv_desc_d, d, range);
	ft_find_best_move_r(&mv_desc_r, d, range);
	if (mv_desc_r.s_loc == -1)
		*mv_desc = mv_desc_d;
	else if (mv_desc_d.s_loc == -1)
		*mv_desc = mv_desc_r;
	else if (mv_desc_d.max < mv_desc_r.max)
		*mv_desc = mv_desc_d;
	else
		*mv_desc = mv_desc_r;
}
