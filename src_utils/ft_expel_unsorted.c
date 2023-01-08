/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expel_unsorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:25:42 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/08 13:10:35 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static void	ft_find_closest_a_n_repos(t_push_swap_data *d, int *range, \
				int half_sz)
{
	t_dllist	*fst_d;
	t_dllist	*fst_r;
	int			loc_d;
	int			loc_r;

	loc_d = half_sz;
	loc_r = half_sz;
	fst_d = ft_dllstfindfirstinrange(&loc_d, d->stack_a->dll, range);
	fst_r = ft_dllstfindfirstinrangerev(&loc_r, d->stack_a->dll, range);
	if (loc_d != -1 && (loc_r == -1 || loc_d < loc_r))
		psd_apply_cmd_xn(d, ra, loc_d, 1);
	else if (loc_r != -1)
		psd_apply_cmd_xn(d, rra, loc_d, 1);
}

static int	ft_must_be_expelled(t_dllist *dll, t_expel_data *ed)
{
	t_stack_el	*se;
	int			max_limit;

	se = dll->content;
	max_limit = ed->pivot + ed->start_sz / 2;
	if (ed->pivot < (ed->start_sz - 1))
		return (se->order < ed->pivot || se->order > max_limit);
	else
		return (se->order > ed->min_pivot);
}

static int	ft_must_be_swapped(t_dllist *dll)
{
	t_stack_el	*se;
	t_stack_el	*next_se;

	se = dll->content;
	next_se = dll->next->content;
	return (next_se->order < se->order);
}

static void	ft_expel_iter(unsigned int i, t_dllist *dll, void *arg)
{
	static t_expel_data		ed;
	t_push_swap_data		*d;
	t_stack_el				*se;

	d = arg;
	se = dll->content;
	if (i == 0)
	{
		ed.start_sz = d->stack_a->size;
		ed.pivot = se->order;
		ed.min_pivot = se->order;
	}
	else
	{
		if (ft_must_be_expelled(dll, &ed))
			psd_apply_cmd(d, pb, 1);
		else if (dll->next != dll && ft_must_be_expelled(dll->next, &ed))
		{
			ed.pivot = se->order;
			psd_apply_cmd(d, rra, 1);
		}
		else if (dll->next != dll && ft_must_be_swapped(dll))
		{
			psd_apply_cmd(d, sa, 1);
			ed.pivot = se->order;
			psd_apply_cmd(d, rra, 1);
		}
	}
}

void	ft_expel_unsorted(t_push_swap_data *d)
{
	int	i;
	int	sz;
	int	range[2];

	range[0] = 0;
	range[1] = d->stack_a->size / 4;
	ft_find_closest_a_n_repos(d, range, d->stack_a->size / 2);
	i = 0;
	sz = d->stack_a->size;
	while (i < sz)
		ft_expel_iter(i++, d->stack_a->dll, d)
}
