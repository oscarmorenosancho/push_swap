/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_n_get_argument.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:35:51 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 23:25:17 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_utils.h>

int	ft_check_n_get_argument(const char *s, int *nbr)
{
	char	*clone;
	int		res;

	if (! s || ! s[0])
		return (0);
	if (s[0] == '+')
		s++;
	*nbr = ft_atoi(s);
	clone = ft_itoa(*nbr);
	res = ! ft_strncmp(s, clone, 20);
	free_x ((void **)&clone);
	return (res);
}
