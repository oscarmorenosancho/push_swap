/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabiteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 09:25:28 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/20 15:05:21 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_tabiteri(int *tab, size_t size, void (*f)(unsigned int, int*))
{
	size_t	i;

	if (tab && f)
	{
		i = 0;
		while (i < size)
		{
			f(i, tab + i);
			i++;
		}
	}
}
