/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_duplicated.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:26:33 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 23:10:49 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_utils.h>

int	ft_check_duplicated(int *tab, size_t size)
{
	size_t	i;

	i = 1;
	while (i < size)
	{
		if (tab[i] == tab[i - 1])
		{
			ft_log_error("A duplicated value was found\n");
			return (0);
		}
		i++;
	}
	return (1);
}
