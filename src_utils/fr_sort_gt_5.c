/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_sort_gt_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:43:07 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/28 17:52:56 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static void	ft_apply_c1xn_n_c2(t_push_swap_data *d, t_stack_cmd sc1, \
				size_t n, t_stack_cmd sc2)
{
	psd_apply_cmd_xn(d, sc1, n);
	psd_apply_cmd(d, sc2);
}

void	ft_move_chunck_to_b(t_push_swap_data *d, int *range)
{
	t_dllist	*fst;
	int			loc;
	int			i;
	int			chunck_size;
	int			half_stack_size;

	chunck_size = range[1] - range[0] + 1;
	half_stack_size = (d->stack_a->size + 1) / 2;
	i = 0;
	while (i < chunck_size)
	{
		ft_sort_2_anb(d);
		loc = half_stack_size;
		fst = ft_dllstfindfirstinrange(&loc, d->stack_a->dll, range);
		if (loc != -1 && loc < half_stack_size)
			ft_apply_c1xn_n_c2(d, ra, loc, pb);
		else
		{
			loc = half_stack_size;
			fst = ft_dllstfindfirstinrangerev(&loc, d->stack_a->dll, range);
			if (loc != -1)
				ft_apply_c1xn_n_c2(d, rra, loc, pb);
		}
		i++;
	}
	//ft_print_stacks(d, "--\n");
}

void	ft_move_chunck_to_a(t_push_swap_data *d, int *range)
{
	t_dllist	*fst;
	int			loc;
	int			i;
	int			chunck_size;
	int			half_stack_size;

	chunck_size = range[1] - range[0] + 1;
	half_stack_size = (d->stack_b->size + 1) / 2;
	i = 0;
	while (i < chunck_size)
	{
		ft_sort_2_anb(d);
		loc = half_stack_size;
		fst = ft_dllstfindfirstinrange(&loc, d->stack_b->dll, range);
		if (loc != -1 && loc < half_stack_size)
			ft_apply_c1xn_n_c2(d, rb, loc, pa);
		else
		{
			loc = half_stack_size;
			fst = ft_dllstfindfirstinrangerev(&loc, d->stack_b->dll, range);
			if (loc != -1)
				ft_apply_c1xn_n_c2(d, rrb, loc, pa);
		}
		i++;
	}
	//ft_print_stacks(d, "--\n");
}

static void	ft_print_range(int *range)
{
	return ;
	ft_putstr_fd("range = [", 1);
	ft_putnbr_fd(range[0], 1);
	ft_putstr_fd(", ", 1);
	ft_putnbr_fd(range[1], 1);
	ft_putstr_fd("]\n", 1);
}

void	ft_move_chuncks_to_b(t_push_swap_data *d, size_t chunk_size)
{
	int	range[2];
	int	size;
	int	chunk_id;
	int	chunk_count;

	size = d->stack_a->size;
	chunk_count = size / chunk_size;
	chunk_id = 0;
	while (chunk_id < chunk_count)
	{
		/*ft_putstr_fd("ft_move_chuncks_to_b chunk_id = ", 1);
		ft_putnbr_fd(chunk_id, 1);
		ft_putstr_fd("\n", 1);*/
		range[0] = chunk_id * chunk_size;
		range[1] = range[0] + chunk_size - 1;
		if ((chunk_count - chunk_id) <= 1)
			range[1] = size - 1;
		ft_print_range(range);
		ft_move_chunck_to_b(d, range);
		chunk_id++;
	}
}

void	ft_move_chuncks_to_a(t_push_swap_data *d, size_t chunk_size)
{
	int	range[2];
	int	size;
	int	chunk_id;
	int	chunk_count;

	size = d->stack_b->size;
	chunk_count = size / chunk_size;
	chunk_id = chunk_count - 1;
	while (chunk_id >= 0)
	{
		/*ft_putstr_fd("ft_move_chuncks_to_a chunk_id = ", 1);
		ft_putnbr_fd(chunk_id, 1);
		ft_putstr_fd("\n", 1);*/
		range[0] = chunk_id * chunk_size;
		range[1] = range[0] + chunk_size - 1;
		if ((chunk_count - chunk_id) <= 1)
			range[1] = size - 1;
		ft_print_range(range);
		ft_move_chunck_to_a(d, range);
		chunk_id--;
	}
}

void	ft_sort_gt_5(t_push_swap_data *d)
{
	int	size;
	int	chunk_size;

	size = d->stack_a->size;
	chunk_size = size / 2;
	while (chunk_size > 16)
	{
		ft_move_chuncks_to_b(d, chunk_size);
		chunk_size /= 2;
		ft_move_chuncks_to_a(d, chunk_size);
		chunk_size /= 2;
	}
	if (chunk_size < 4)
		ft_move_chuncks_to_b(d, 4);
	else
		ft_move_chuncks_to_b(d, chunk_size);
	ft_move_chuncks_to_a(d, 1);
}
