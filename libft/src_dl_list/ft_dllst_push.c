/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllst_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:52:46 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/19 15:41:30 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dl_list.h"

void	ft_dllst_push(t_dllist **dst, t_dllist **src)
{
	if (dst && src && *src)
		ft_dllstadd_front(dst, ft_dllst_extract(src));
}
