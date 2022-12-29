/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum_pow2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:28:17 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/29 14:32:28 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	ft_pow_2(int n)
{
	return (1 << n);
}

int	ft_sum_pow_2(int n)
{
	int	i;
	int	acc;

	i = 0;
	acc = 0;
	while (i < n)
	{
		acc <<= 1;
		acc |= 1;
		i++;
	}
	return (acc);
}

int	ft_get_sum_pow_lt(int n)
{
	int	i;
	int	acc;
	int	acc2;

	if (n < 2)
		return (1);
	i = 0;
	acc = n;
	acc2 = 1;
	while (acc)
	{
		acc2 <<= 1;
		acc2 |= 1;
		acc >>= 1;
		i++;
	}
	return (acc2 >> 1);
}
