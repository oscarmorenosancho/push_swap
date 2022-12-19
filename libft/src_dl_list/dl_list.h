/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:24:24 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/19 15:42:10 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DL_LIST_H
# define DL_LIST_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dllist
{
	void			*content;
	struct s_dllist	*prev;
	struct s_dllist	*next;
}	t_dllist;

t_dllist	*ft_dllstnew(void *content);
void		ft_dllstadd_front(t_dllist **lst, t_dllist *nn);
int			ft_dllstsize(t_dllist *lst);
t_dllist	*ft_dllstlast(t_dllist *lst);
void		ft_dllstadd_back(t_dllist **lst, t_dllist *nn);
void		ft_dllstdelone(t_dllist *lst, void (*del)(void *));
void		ft_dllstclear(t_dllist **lst, void (*del)(void *));
void		ft_dllstiter(t_dllist *lst, void (*f)(void *));
t_dllist	*ft_dllstmap(t_dllist *lst, void *(*f)(void *), \
			void (*del)(void *));
void		ft_dllst_rotate(t_dllist **lst);
void		ft_dllst_revrotate(t_dllist **lst);
void		ft_dllst_swap(t_dllist **lst);
t_dllist	*ft_dllst_extract(t_dllist **lst);
void		ft_dllst_push(t_dllist **dst, t_dllist **src);

#endif
