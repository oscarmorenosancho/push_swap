/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:53:08 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 13:34:42 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_mand.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*p;
	char	*pe;

	if (! n)
		return (NULL);
	p = (char *)s;
	pe = (char *)s + n - 1;
	while (p < pe && *p != (char)c)
		p++;
	if (*p != (char)c)
		return (NULL);
	return (p);
}
