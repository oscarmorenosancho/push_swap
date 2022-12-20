/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:24:51 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/20 16:17:16 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H
# include "../libft/libft.h"

typedef struct s_stack_el
{
	int	nbr;
	int	order;
}	t_stack_el;

int			ft_check_duplicated(int *tab, size_t size);
int			ft_check_n_get_argument(const char *s, int *nbr);
int			*ft_take_arguments(size_t *size, int argc, char const *argv[]);
void		ft_log_err_exit(char *msg, int **p);
t_dllist	*ft_new_stack_el(int nbr, int order);

#endif