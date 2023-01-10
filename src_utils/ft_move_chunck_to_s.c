/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_chunck_to_s.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:16:28 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/10 11:17:20 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	ft_move_chunck_to_b(t_push_swap_data *d, int *range, int not_dest)
{
	int			i;
	int			chunck_size;
	t_move_desc	mv_desc;

	if (range[1] >= range[0])
		chunck_size = range[1] - range[0] + 1;
	else
		chunck_size = range[0] - range[1] + 1;
	mv_desc.not_dest = not_dest;
	mv_desc.a_b = 1;
	i = 0;
	while (i < chunck_size)
	{
		ft_find_best_move(&mv_desc, d, range);
		mv_desc.not_dest = not_dest;
		if (mv_desc.s_loc != -1)
			psd_apply_move(d, &mv_desc);
		i++;
	}
}

void	ft_move_chunck_to_a(t_push_swap_data *d, int *range, int not_dest)
{
	int			i;
	int			chunck_size;
	t_move_desc	mv_desc;

	if (range[1] >= range[0])
		chunck_size = range[1] - range[0] + 1;
	else
		chunck_size = range[0] - range[1] + 1;
	mv_desc.not_dest = not_dest;
	mv_desc.a_b = 0;
	i = 0;
	while (i < chunck_size)
	{
		ft_find_best_move(&mv_desc, d, range);
		mv_desc.not_dest = not_dest;
		if (mv_desc.s_loc != -1)
			psd_apply_move(d, &mv_desc);
		i++;
	}
}

void	ft_move_best_to_b(t_push_swap_data *d, int *range, int not_dest)
{
	t_move_desc	mv_desc;

	mv_desc.not_dest = not_dest;
	mv_desc.a_b = 1;
	ft_find_best_move(&mv_desc, d, range);
	mv_desc.not_dest = not_dest;
	if (mv_desc.s_loc != -1)
		psd_apply_move(d, &mv_desc);
}

void	ft_move_best_to_a(t_push_swap_data *d, int *range, int not_dest)
{
	t_move_desc	mv_desc;

	mv_desc.not_dest = not_dest;
	mv_desc.a_b = 0;
	ft_find_best_move(&mv_desc, d, range);
	mv_desc.not_dest = not_dest;
	if (mv_desc.s_loc != -1)
		psd_apply_move(d, &mv_desc);
}
