/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_data_class2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:24:33 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/02 15:10:27 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	psd_apply_cmd_xn(t_push_swap_data *psd, t_stack_cmd sc, \
						size_t n, int dis_dbl)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 1;
	while (ret && i < n)
	{
		ret = (ret && psd_apply_cmd(psd, sc, dis_dbl));
		i++;
	}
	return (ret);
}

void	ft_apply_c1xn_n_c2(t_push_swap_data *d, t_stack_cmd sc1, \
			size_t n, t_stack_cmd sc2)
{
	psd_apply_cmd_xn(d, sc1, n, 0);
	psd_apply_cmd(d, sc2, 0);
}

void	ft_apply_c1xn_n_c2_dd(t_push_swap_data *d, t_stack_cmd sc1, \
			size_t n, t_stack_cmd sc2)
{
	psd_apply_cmd_xn(d, sc1, n, 1);
	psd_apply_cmd(d, sc2, 1);
}

int	ft_find_ins_loc_in_dir(t_push_swap_data *d, \
			int d_r, t_ips_opt *ips_opt)
{
	t_dllist	*l;
	int			s_loc;

	l = d->stack_b->dll;
	if (ips_opt->sort_dir == sd_asc)
		l = d->stack_a->dll;
	if (d_r)
		ft_dllstfindfirstinsertlocrev (&s_loc, l, ips_opt);
	else
		ft_dllstfindfirstinsertloc (&s_loc, l, ips_opt);
	return (s_loc);
}

void	psd_move_from_loc_to_ins_d(t_push_swap_data *d, int a_b, \
			size_t loc, int order)
{
	t_ips_opt	ips_opt;
	t_stack_cmd	sc1;
	t_stack_cmd	sc2;
	t_stack_cmd	sc3;
	int			d_loc;

	ips_opt.order = order;
	ips_opt.sort_dir = sd_asc;
	sc1 = ra;
	sc2 = rb;
	sc3 = pb;
	if (a_b)
	{
		ips_opt.sort_dir = sd_desc;
		sc1 = rb;
		sc2 = ra;
		sc3 = pa;
	}
	d_loc = ft_find_ins_loc_in_dir(d, 0, &ips_opt);
	psd_apply_cmd_xn(d, sc1, loc, 0);
	psd_apply_cmd_xn(d, sc2, loc, 0);
	psd_apply_cmd(d, sc3, 0);
}
