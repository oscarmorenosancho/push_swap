/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expel_unsorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:25:42 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/09 11:12:33 by omoreno-         ###   ########.fr       */
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
	max_limit = ed->pivot + ed->start_sz / 16;
	if (ed->run == 0)
	{
		if (se->order < ed->max)
			return (se->order < ed->pivot || se->order > max_limit);
		else
			return (se->order > ed->min_pivot);
	}
	else
	{
		return (se->order > ed->min_pivot || se->order < ed->pivot);
	}
}

/*static int	ft_must_be_swapped(t_dllist *dll, t_expel_data *ed)
{
	t_stack_el	*se;
	t_stack_el	*next_se;

	se = dll->content;
	next_se = dll->next->content;
	if (se->order < ed->max)
		return (next_se->order < se->order);
	return (0);
}*/

static void	ft_expel_iter(unsigned int i, t_push_swap_data *d, int max)
{
	static t_expel_data		ed;
	t_dllist				*dll;
	t_stack_el				*se;

	dll = d->stack_a->dll;
	se = dll->content;
	ed.max = max;
	if (i == 0)
	{
		ed.start_sz = d->stack_a->size;
		ed.pivot = se->order;
		ed.min_pivot = se->order;
		ed.run = 0;
	}
	else
	{
		if (ft_must_be_expelled(dll, &ed))
			psd_apply_cmd(d, pb, 1);
		/*else if (dll->next != dll && ft_must_be_expelled(dll->next, &ed))
		{
			ed.pivot = se->order;
			psd_apply_cmd(d, ra, 1);
		}
		else if (dll->next != dll && ft_must_be_swapped(dll, &ed))
		{
			psd_apply_cmd(d, sa, 1);
			ed.pivot = se->order;
			psd_apply_cmd(d, ra, 1);
		}*/
		else
		{
			ed.pivot = se->order;
			psd_apply_cmd(d, ra, 1);
		}
	}
}

void	ft_expel_unsorted(t_push_swap_data *d)
{
	int			i;
	int			sz;
	int			range[2];
	t_sort_anal	*s_anal;

	range[0] = 0;
	range[1] = d->stack_a->size / 8;
	ft_find_closest_a_n_repos(d, range, d->stack_a->size / 2);
	i = 0;
	sz = d->stack_a->size;
	s_anal = ft_sort_anal(sd_asc, d->stack_a->dll, d->stack_a->size);
	while (i <= sz && ! s_anal->is_sorted)
	{
		ft_expel_iter(i, d, s_anal->max);
		free_x((void **)&s_anal);
		s_anal = ft_sort_anal(sd_asc, d->stack_a->dll, d->stack_a->size);
		i++;
	}
	free_x((void **)&s_anal);
}
