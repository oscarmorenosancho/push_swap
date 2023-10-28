/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_data_class2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:24:33 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 23:10:48 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_utils.h>

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
