/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:09:22 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 13:34:42 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_mand.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*pd;
	char	*ps;
	char	*pe;

	if (dst != src)
	{
		pd = (char *)dst;
		ps = (char *)src;
		pe = ps + n;
		while (ps < pe)
		{
			*pd = *ps;
			pd++;
			ps++;
		}
	}
	return (dst);
}
