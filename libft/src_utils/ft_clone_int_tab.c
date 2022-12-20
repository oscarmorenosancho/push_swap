/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clone_int_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:01:46 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/20 13:18:18 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	*ft_clone_int_tab(const int *src, size_t size)
{
	int		*dst;

	if (size < 1 || ! src)
		return (NULL);
	dst = malloc (size * sizeof(int));
	if (dst)
		ft_memcpy(dst, src, size * sizeof(int));
	return (dst);
}
