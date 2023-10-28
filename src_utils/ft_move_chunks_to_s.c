/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_chunks_to_s.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:30:00 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 23:10:49 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_utils.h>

void	ft_move_chuncks_to_b(t_push_swap_data *d, size_t chunk_size, \
			int not_dest)
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
		range[0] = chunk_id * chunk_size;
		range[1] = range[0] + chunk_size - 1;
		if ((chunk_count - chunk_id) <= 1)
			range[1] = size - 1;
		ft_move_chunck_to_b(d, range, not_dest);
		chunk_id++;
	}
	range[0] = 0;
	range[1] = d->size;
	while (d->stack_a->size > 0)
		ft_move_best_to_b(d, range, not_dest);
}

void	ft_move_chuncks_to_a(t_push_swap_data *d, size_t chunk_size, \
			int not_dest)
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
		range[0] = chunk_id * chunk_size;
		range[1] = range[0] + chunk_size - 1;
		if ((chunk_count - chunk_id) <= 1)
			range[1] = size - 1;
		ft_move_chunck_to_a(d, range, not_dest);
		chunk_id--;
	}
	range[0] = 0;
	range[1] = d->size;
	while (d->stack_b->size > 0)
		ft_move_best_to_a(d, range, not_dest);
}

void	ft_move_shr_chuncks_to_b(t_push_swap_data *d, size_t chunk_size, \
			int not_dest)
{
	int	range[2];
	int	size;
	int	i;

	size = d->size;
	range[0] = 0;
	range[1] = chunk_size - 1;
	i = 0;
	while (range[0] < size)
	{
		ft_move_chunck_to_b(d, range, not_dest);
		if (fr_is_convinient_cmd_in_both(d, sa))
			psd_apply_cmd(d, sb, 1);
		range[0] = range[1] + 1;
		if (chunk_size > 3)
		{
			if (i % 3 == 1 && d->size > 100)
				chunk_size /= 2;
			range[1] = range[0] + chunk_size - 1;
		}
		else
			range[1] = d->size;
		i++;
	}
}
