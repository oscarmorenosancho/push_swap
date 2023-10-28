/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:38:55 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 13:34:42 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_mand.h>

char	*ft_strdup(const char *s1)
{
	void	*s2;
	int		len;

	len = ft_strlen(s1);
	s2 = malloc(len + 1);
	if (s2)
		ft_memcpy(s2, s1, len + 1);
	return (s2);
}
