/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:14:45 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 13:34:42 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_mand.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	n_len;
	char	*p;

	n_len = ft_strlen(needle);
	if (n_len == 0 || haystack == needle)
		return ((char *)haystack);
	p = (char *)haystack;
	i = 0;
	while (p[i] && i < len)
	{
		c = 0;
		while (p[i + c] && needle[c] && p[i + c] == needle[c] \
					&& i + c < len)
			c++;
		if (c == n_len)
			return (p + i);
		i++;
	}
	return (NULL);
}
