/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:33:59 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/19 13:06:11 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dl_list.h"

void	ft_lstdelone(t_dllist *lst, void (*del)(void *))
{
	if (del)
		(*del)(lst->content);
	free((void *)lst);
}
