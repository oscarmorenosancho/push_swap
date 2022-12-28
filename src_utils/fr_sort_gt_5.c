/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_sort_gt_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:43:07 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/28 15:14:00 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	ft_move_chunck(t_push_swap_data *d, int *range)
{
	t_dllist	*fst;
	int			loc;
	int			i;
	int			chunck_size;
	int			half_stack_size;

	chunck_size = range[1] - range[0] + 1;
	half_stack_size = d->stack_a->size / 2;
	i = 0;
	while (i < chunck_size)
	{
		fst = ft_dllstfindfirstinrange(&loc, d->stack_a->dll, range);
		ft_putstr_fd("ft_dllstfindfirstinrange, loc = ", 1);
		ft_putnbr_fd(loc, 1);
		ft_putstr_fd("\n", 1);
		if (loc != -1 && loc < half_stack_size)
		{
			psd_apply_cmd_xn(d, ra, loc);
			psd_apply_cmd(d, pb);
		}
		else
		{
			fst = ft_dllstfindfirstinrangerev(&loc, d->stack_a->dll, range);
			ft_putstr_fd("ft_dllstfindfirstinrangerev, loc = ", 1);
			ft_putnbr_fd(loc, 1);
			ft_putstr_fd("\n", 1);
			if (loc != -1)
			{
				psd_apply_cmd_xn(d, rra, loc);
				psd_apply_cmd(d, pb);
			}
		}
		i++;
	}
	ft_print_stacks(d, "--\n");
}

void	ft_sort_gt_5(t_push_swap_data *d)
{
	int	range[2];
	int	size;
	int	chunk_id;
	int	chunk_count;
	int	chunk_size;

	chunk_size = 1;
	size = d->stack_a->size;
	chunk_count = size / chunk_size;
	chunk_id = 0;
	while (chunk_id < chunk_count)
	{
		ft_putstr_fd("ft_sort_gt_5 chunk_id = ", 1);
		ft_putnbr_fd(chunk_id, 1);
		ft_putstr_fd("\n", 1);
		range[0] = chunk_id * chunk_size;
		range[1] = range[0] + chunk_size - 1;
		if ((chunk_count - chunk_id) <= 1)
			range[1] = size - 1;
		ft_putstr_fd("range = [", 1);
		ft_putnbr_fd(range[0], 1);
		ft_putstr_fd(", ", 1);
		ft_putnbr_fd(range[1], 1);
		ft_putstr_fd("]\n", 1);
		ft_move_chunck(d, range);
		chunk_id++;
	}
}
