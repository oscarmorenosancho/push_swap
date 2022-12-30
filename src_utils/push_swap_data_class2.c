/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_data_class2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:24:33 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/30 11:44:39 by omoreno-         ###   ########.fr       */
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
