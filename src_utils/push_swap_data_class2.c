/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_data_class2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:24:33 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/23 11:31:42 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	psd_apply_cmd_xn(t_push_swap_data *psd, t_stack_cmd sc, size_t n)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 1;
	while (ret && i++ < n)
		ret = (ret && psd_apply_cmd(psd, sc));
	return (ret);
}