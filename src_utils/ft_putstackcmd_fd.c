/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstackcmd_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:26:52 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/23 11:17:47 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	ft_putstackcmd_fd(t_stack_cmd sc, int fd)
{
	if (sc == sa)
		ft_putstr_fd("sa\n", fd);
	else if (sc == sb)
		ft_putstr_fd("sb\n", fd);
	else if (sc == ss)
		ft_putstr_fd("ss\n", fd);
	else if (sc == pa)
		ft_putstr_fd("pa\n", fd);
	else if (sc == pb)
		ft_putstr_fd("pb\n", fd);
	else if (sc == ra)
		ft_putstr_fd("ra\n", fd);
	else if (sc == rb)
		ft_putstr_fd("rb\n", fd);
	else if (sc == rr)
		ft_putstr_fd("rr\n", fd);
	else if (sc == rra)
		ft_putstr_fd("rra\n", fd);
	else if (sc == rrb)
		ft_putstr_fd("rrb\n", fd);
	else if (sc == rrr)
		ft_putstr_fd("rrr\n", fd);
}

static void	fn_printstackcmd(unsigned int i, void *content, void *arg)
{
	t_stack_cmd	sc;
	int			fd;

	(void)i;
	sc = (t_stack_cmd)content;
	fd = (int)arg;
	ft_putstackcmd_fd(sc, fd);
}

void	ft_putstackcmdlst_fd(t_list *scl, int fd)
{
	ft_lstreduce(scl, &fn_printstackcmd, (void *)(long)fd);
}
