/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstackcmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:35:47 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 23:10:49 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_utils.h>

static t_stack_cmd	ft_getstackcmd_s(char *sc)
{
	if (sc[1] == 'a')
		return (sa);
	else if (sc[1] == 'b')
		return (sb);
	else if (sc[1] == 's')
		return (ss);
	else
		return (nop);
}

static t_stack_cmd	ft_getstackcmd_p(char *sc)
{
	if (sc[1] == 'a')
		return (pa);
	else if (sc[1] == 'b')
		return (pb);
	else
		return (nop);
}

static t_stack_cmd	ft_getstackcmd_rr(char *sc)
{
	if (sc[2] == 'a')
		return (rra);
	else if (sc[2] == 'b')
		return (rrb);
	else if (sc[2] == 'r')
		return (rrr);
	else
		return (nop);
}

static t_stack_cmd	ft_getstackcmd_r(char *sc)
{
	if (sc[1] == 'a')
		return (ra);
	else if (sc[1] == 'b')
		return (rb);
	else if (sc[1] == 'r')
		return (rr);
	else
		return (nop);
}

t_stack_cmd	ft_getstackcmd(char *sc)
{
	int	line_size;

	line_size = ft_linelen(sc);
	if (line_size > 3 || line_size < 2)
		return (nop);
	if (sc[0] == 's' && line_size == 2)
		return (ft_getstackcmd_s(sc));
	if (sc[0] == 'p' && line_size == 2)
		return (ft_getstackcmd_p(sc));
	if (sc[0] == 'r' && sc[1] == 'r' && line_size == 3)
		return (ft_getstackcmd_rr(sc));
	if (sc[0] == 'r' && line_size == 2)
		return (ft_getstackcmd_r(sc));
	return (nop);
}
