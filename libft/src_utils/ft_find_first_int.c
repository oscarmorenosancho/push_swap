/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_first_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:14:55 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/20 16:25:26 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_find_first_int(int *tab, size_t size, \
						int (*f)(unsigned int, int, int), int arg)
{
	int	i;

	if (tab && f)
	{
		i = 0;
		while (i < (int)size && !f(i, tab[i], arg))
			i++;
		if (i < (int)size)
			return (i);
	}
	return (-1);
}
