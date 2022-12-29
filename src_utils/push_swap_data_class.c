/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_data_class.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:34:44 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/29 20:54:08 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

t_push_swap_data	*psd_constructor(void)
{
	t_push_swap_data	*psd;

	psd = ft_calloc(1, sizeof(t_push_swap_data));
	psd->stack_a = pss_constructor();
	psd->stack_b = pss_constructor();
	psd->cmd_list = NULL;
	return (psd);
}

void	psd_dispose(t_push_swap_data **psd)
{
	t_push_swap_data	*d;

	if (!psd)
		return ;
	d = *psd;
	free_x((void **)&d->sorted);
	free_x((void **)&d->tab);
	pss_dispose(&d->stack_a);
	pss_dispose(&d->stack_b);
	ft_lstclear(&d->cmd_list, NULL);
	free(d);
	d = NULL;
}

static void	psd_exe_c_cmd(t_push_swap_data *psd, t_stack_cmd sc)
{
	if (sc == ss)
	{
		pss_swap(psd->stack_a);
		pss_swap(psd->stack_b);
	}
	else if (sc == rr)
	{
		pss_rotate(psd->stack_a);
		pss_rotate(psd->stack_b);
	}
	else if (sc == rrr)
	{
		pss_revrotate(psd->stack_a);
		pss_revrotate(psd->stack_b);
	}
}

static void	psd_exe_cmd(t_push_swap_data *psd, t_stack_cmd sc)
{
	if (sc == sa)
		pss_swap(psd->stack_a);
	else if (sc == sb)
		pss_swap(psd->stack_b);
	else if (sc == pa)
		pss_push(psd->stack_a, psd->stack_b);
	else if (sc == pb)
		pss_push(psd->stack_b, psd->stack_a);
	else if (sc == ra)
		pss_rotate(psd->stack_a);
	else if (sc == rb)
		pss_rotate(psd->stack_b);
	else if (sc == rra)
		pss_revrotate(psd->stack_a);
	else if (sc == rrb)
		pss_revrotate(psd->stack_b);
	else
		psd_exe_c_cmd(psd, sc);
}

int	psd_apply_cmd(t_push_swap_data *psd, t_stack_cmd sc, int dis_dbl)
{
	t_list			*ln;
	t_stack_cmd		sca;

	if (! psd)
		return (0);
	ln = ft_calloc(1, sizeof(t_list));
	if (! ln)
		return (0);
	sca = sc;
	if (fr_is_convinient_cmd_in_both(psd, sc) && !dis_dbl)
	{
		if (sc == ra || sc == rb)
			sca = rr;
		else if (sc == rra || sc == rrb)
			sca = rrr;
		else if (sc == sa || sc == sb)
			sca = ss;
	}		
	ln->content = (void *)sca;
	ft_lstadd_front(&psd->cmd_list, ln);
	psd_exe_cmd(psd, sca);
	return (1);
}
