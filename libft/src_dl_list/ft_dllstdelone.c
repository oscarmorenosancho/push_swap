/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:33:59 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 13:37:32 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dl_list.h>

void	ft_dllstdelone(t_dllist *lst, void (*del)(void *))
{
	if (del)
		(*del)(lst->content);
	free((void *)lst);
}
