/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_chunks_to_s.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:30:00 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/08 16:54:06 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static void	ft_print_range(int *range)
{
	return ;
	ft_putstr_fd("range = [", 1);
	ft_putnbr_fd(range[0], 1);
	ft_putstr_fd(", ", 1);
	ft_putnbr_fd(range[1], 1);
	ft_putstr_fd("]\n", 1);
}

void	ft_move_chuncks_to_b(t_push_swap_data *d, size_t scale, \
		int not_dest)
{
	int	range[2];
	int	size;
	int	chunk_size;

	size = d->stack_a->size;
	chunk_size = (size / 2) / scale;
	range[0] = 0;
	range[1] = size >> 1;
	while (range[1] < size)
	{
		ft_print_range(range);
		ft_move_chunck_to_b(d, range, not_dest);
		range[0] = range[1] + 1;
		chunk_size >>= 1;
		if (chunk_size < 1)
			chunk_size = 1;
		range[1] = range[0] + chunk_size;
	}
}

void	ft_move_chuncks_to_a(t_push_swap_data *d, size_t scale, \
		int not_dest)
{
	int	range[2];
	int	size;
	int	chunk_size;

	size = d->stack_b->size;
	chunk_size = (size / 2) / scale;
	range[0] = size >> 1;
	range[1] = size - 1;
	while (range[0] >= 0)
	{
		ft_print_range(range);
		ft_move_chunck_to_a(d, range, not_dest);
		range[1] = range[0] - 1;
		chunk_size >>= 1;
		if (chunk_size < 1)
			chunk_size = 1;
		range[0] = range[1] - chunk_size;
	}
}

void	ft_move_eq_chuncks_to_b(t_push_swap_data *d, size_t chunk_size, \
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
		ft_print_range(range);
		ft_move_chunck_to_b(d, range, not_dest);
		chunk_id++;
	}
}

void	ft_move_eq_chuncks_to_a(t_push_swap_data *d, size_t chunk_size, \
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
		ft_print_range(range);
		ft_move_chunck_to_a(d, range, not_dest);
		chunk_id--;
	}
}
