/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_best_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:00:13 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/09 10:27:12 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	ft_print_move(t_move_desc *mv_desc, char *tittle)
{
	ft_putstr_fd(tittle, 2);
	if (mv_desc->a_b)
		ft_putstr_fd("a -> b\n", 2);
	else
		ft_putstr_fd("b -> a\n", 2);
	if (mv_desc->s_d_r)
		ft_putstr_fd("src rev\n", 2);
	else
		ft_putstr_fd("src dir\n", 2);
	ft_putstr_fd("src dist: ", 2);
	ft_putnbr_fd(mv_desc->s_loc, 2);
	ft_putstr_fd("\n", 2);
	if (mv_desc->d_d_r)
		ft_putstr_fd("dest rev\n", 2);
	else
		ft_putstr_fd("dest dir\n", 2);
	ft_putstr_fd("dest dist: ", 2);
	ft_putnbr_fd(mv_desc->d_loc, 2);
	ft_putstr_fd("\nmax dist: ", 2);
	ft_putnbr_fd(mv_desc->max, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_find_best_move(t_move_desc *mv_desc, \
			t_push_swap_data *d, int *range)
{
	t_move_desc	mv_desc_d;
	t_move_desc	mv_desc_r;

	mv_desc_d = *mv_desc;
	mv_desc_r = *mv_desc;
	ft_find_best_move_d(&mv_desc_d, d, range);
	ft_find_best_move_r(&mv_desc_r, d, range);
	if (mv_desc_d.max < mv_desc_r.max)
		*mv_desc = mv_desc_d;
	else
		*mv_desc = mv_desc_r;
}
