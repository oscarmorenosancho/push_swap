/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:24:51 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/21 17:46:26 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H
# include "../libft/libft.h"

typedef enum e_stack_cmd
{
	sa = 0,
	sb = 1,
	ss = 2,
	pa = 3,
	pb = 4,
	ra = 5,
	rb = 6,
	rr = 7,
	rra = 8,
	rrb = 9,
	rrr = 10
}	t_stack_cmd;

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
t_dllist	*ft_dllstfindfirstinrange(int *loc, t_dllist *lst, int *range);
t_dllist	*ft_dllstfindfirstinrangerev(int *loc, t_dllist *lst, int *range);
int			ft_stack_head_order_n_bit(t_dllist *dll, int n);
void		ft_putstackcmd_fd(t_stack_cmd sc, int fd);

#endif