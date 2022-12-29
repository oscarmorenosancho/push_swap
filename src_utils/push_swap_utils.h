/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:24:51 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/29 17:33:12 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H
# include "../libft/libft.h"

typedef enum e_stack_cmd
{
	nop,
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_stack_cmd;

typedef struct s_stack_el
{
	int	nbr;
	int	order;
}	t_stack_el;

typedef struct s_ps_stack
{
	t_dllist	*dll;
	size_t		size;
}	t_ps_stack;

typedef struct s_push_swap_data
{
	int			*tab;
	int			*sorted;
	size_t		size;
	t_ps_stack	*stack_a;
	t_ps_stack	*stack_b;
	t_list		*cmd_list;
}	t_push_swap_data;

int					ft_check_duplicated(int *tab, size_t size);
int					ft_check_n_get_argument(const char *s, int *nbr);
int					*ft_take_arguments(t_push_swap_data **p, \
						int argc, char const *argv[]);
void				ft_log_err_exit(char *msg, t_push_swap_data **p);
t_dllist			*ft_new_stack_el(int nbr, int order);
t_dllist			*ft_dllstfindfirstinrange(int *loc, \
						t_dllist *lst, int *range);
t_dllist			*ft_dllstfindfirstinrangerev(int *loc, \
						t_dllist *lst, int *range);
int					ft_stack_head_order_n_bit(t_dllist *dll, int n);
void				ft_putstackcmd_fd(t_stack_cmd sc, int fd);
void				ft_putstackcmdlst_fd(t_list *scl, int fd);
t_stack_cmd			ft_getstackcmd(char *sc);
int					ft_check_stack_ordered(t_dllist *dll);
t_ps_stack			*pss_constructor(void);
void				pss_clear(t_ps_stack *pss);
void				pss_dispose(t_ps_stack **pss);
void				pss_add_front(t_ps_stack *pss, t_dllist *nn);
void				pss_add_back(t_ps_stack *pss, t_dllist *nn);
t_dllist			*pss_extract(t_ps_stack *pss);
void				pss_push(t_ps_stack *dst, t_ps_stack *src);
void				pss_swap(t_ps_stack *pss);
void				pss_rotate(t_ps_stack *pss);
void				pss_revrotate(t_ps_stack *pss);
void				ft_print_tab(int *tab, size_t size);
void				ft_print_el(void *content);
void				ft_print_stack(t_ps_stack *stack, char name, char *sep);
void				ft_print_stacks(t_push_swap_data *d, char *sep);
t_ps_stack			*ft_fill_stack_with_tab(t_ps_stack	*dst, int *tab, \
						int *sorted, size_t size);
t_push_swap_data	*psd_constructor(void);
void				psd_dispose(t_push_swap_data **psd);
int					psd_apply_cmd(t_push_swap_data *psd, t_stack_cmd sc, \
						int dis_dbl);
int					psd_apply_cmd_xn(t_push_swap_data *psd, t_stack_cmd sc, \
						size_t n, int dis_dbl);
void				ft_read_n_play_cmd_list_fd(t_push_swap_data	*psd, int fd);
void				ft_sort_2_a_b(t_push_swap_data *d);
void				ft_sort_2_b_a(t_push_swap_data *d);
void				ft_sort_2_anb(t_push_swap_data *d);
void				ft_sort_3_a(t_push_swap_data *d);
void				ft_ins_into_4(t_push_swap_data *d, size_t in4);
void				ft_sort_4_5_a(t_push_swap_data *d);
void				ft_sort_gt_5(t_push_swap_data *d);
int					fr_is_convinient_cmd_in_both(t_push_swap_data *psd, \
						t_stack_cmd sc);
int					ft_pow_2(int n);
int					ft_sum_pow_2(int n);
int					ft_get_sum_pow_lt(int n);

#endif