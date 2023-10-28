/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_anal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:04:26 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 23:10:48 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_utils.h>

static int	ft_is_sorted(t_sort_dir	sd, int prev, int cur)
{
	if (sd == sd_asc)
		return (prev < cur);
	else if (sd == sd_desc)
		return (prev > cur);
	else
		return (0);
}

static int	ft_content_order(t_dllist *dll)
{
	t_stack_el	*el;

	el = dll->content;
	return (el->order);
}

static void	update_max_min(t_sort_anal *s_anal, int cur, int loc)
{
	if (cur > s_anal->max)
	{
		s_anal->max = cur;
		s_anal->max_loc = loc;
	}
	if (cur < s_anal->min)
	{
		s_anal->min = cur;
		s_anal->min_loc = loc;
	}
}

static void	update_anal(unsigned int i, t_dllist *dll, void *arg)
{
	t_sort_anal	*s_anal;
	t_dllist	*prev;
	int			sorted;

	prev = dll->prev;
	s_anal = arg;
	sorted = ft_is_sorted(s_anal->sd, \
						ft_content_order(prev), ft_content_order(dll));
	if (! sorted && s_anal->sd == sd_asc)
	{
		if (s_anal->runs == 0 && \
			(ft_content_order(dll) < s_anal->min || i == 0))
			s_anal->runs++;
		else
			s_anal->is_sorted = 0;
	}
	else if (! sorted && s_anal->sd == sd_desc)
	{
		if (s_anal->runs == 0 && \
			(ft_content_order(dll) > s_anal->max || i == 0))
			s_anal->runs++;
		else
			s_anal->is_sorted = 0;
	}
	update_max_min(s_anal, ft_content_order(dll), i);
}

t_sort_anal	*ft_sort_anal(t_sort_dir sd, t_dllist *dll, int size)
{
	t_sort_anal	*s_anal;

	if (! size || !dll)
		return (NULL);
	s_anal = malloc(sizeof(t_sort_anal));
	if (! s_anal)
		return (s_anal);
	s_anal->sd = sd;
	s_anal->size = size;
	s_anal->max = ft_content_order(dll);
	s_anal->min = ft_content_order(dll);
	s_anal->max_loc = 0;
	s_anal->min_loc = 0;
	s_anal->is_sorted = 1;
	s_anal->runs = 0;
	ft_dllst_reduce(dll, &update_anal, s_anal);
	return (s_anal);
}
