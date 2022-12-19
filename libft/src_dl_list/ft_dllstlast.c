/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllstlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:18:09 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/19 13:13:22 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dl_list.h"

t_dllist	*ft_lstlast(t_dllist *lst)
{
	t_dllist	*last;

	last = NULL;
	if (lst)
		last = lst->prev;
	return (last);
}
