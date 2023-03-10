/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:51:30 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/02 12:56:37 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../libft.h"

void	ft_sort_int_tab(int *tab, int size);
int		*ft_clone_int_tab(const int *src, size_t size);
void	ft_tabiteri(int *tab, size_t size, void (*f)(unsigned int, int*));
int		ft_find_first_int(int *tab, size_t size, \
			int (*f)(unsigned int, int, int), int arg);
int		ft_max(int a, int b);
int		ft_min(int a, int b);

#endif