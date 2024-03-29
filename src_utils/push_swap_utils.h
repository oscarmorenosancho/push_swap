/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:24:51 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 23:24:24 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H
# include <libft.h>

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

typedef enum e_sort_dir
{
	sd_desc,
	sd_asc
}	t_sort_dir;

typedef struct s_stack_el
{
	int	nbr;
	int	order;
}	t_stack_el;

typedef struct s_ips_opt
{
	t_sort_dir	sort_dir;
	int			order;
	int			size;
}	t_ips_opt;

typedef struct s_ps_stack
{
	t_dllist	*dll;
	size_t		size;
}	t_ps_stack;

typedef struct s_move_desc
{
	int		s_loc;
	int		s_d_r;
	int		d_loc;
	int		d_d_r;
	int		a_b;
	int		max;
	int		not_dest;
}	t_move_desc;

typedef struct s_sort_anal
{
	t_sort_dir	sd;
	int			size;
	int			is_sorted;
	int			runs;
	int			min;
	int			max;
	int			min_loc;
	int			max_loc;
}	t_sort_anal;

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
t_dllist			*ft_dllstfindfirstinsertloc(int *loc, t_dllist *lst, \
						t_ips_opt *ips_opt);
t_dllist			*ft_dllstfindfirstinsertlocrev(int *loc, t_dllist *lst, \
						t_ips_opt *ips_opt);
t_sort_anal			*ft_sort_anal(t_sort_dir sd, t_dllist *dll, int size);
int					ft_stack_head_order_n_bit(t_dllist *dll, int n);
void				ft_putstackcmd_fd(t_stack_cmd sc, int fd);
void				ft_putstackcmdlst_fd(t_list *scl, int fd);
t_stack_cmd			ft_getstackcmd(char *sc);
int					ft_check_stack_ordered(t_ps_stack *stk);
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
t_ps_stack			*ft_fill_stack_with_tab(t_ps_stack	*dst, int *tab, \
						int *sorted, size_t size);
t_push_swap_data	*psd_constructor(void);
void				psd_dispose(t_push_swap_data **psd);
int					psd_apply_cmd(t_push_swap_data *psd, t_stack_cmd sc, \
						int dis_dbl);
int					psd_apply_cmd_xn(t_push_swap_data *psd, t_stack_cmd sc, \
						size_t n, int dis_dbl);
void				psd_apply_move(t_push_swap_data *d, t_move_desc *mv_desc);
void				ft_read_n_play_cmd_list_fd(t_push_swap_data	*psd, int fd);
void				ft_find_best_move_d(t_move_desc *mv_desc, \
						t_push_swap_data *d, int *range);
void				ft_find_best_move_r(t_move_desc *mv_desc, \
						t_push_swap_data *d, int *range);
void				ft_find_best_move(t_move_desc *mv_desc, \
						t_push_swap_data *d, int *range);
void				ft_move_chunck_to_b(t_push_swap_data *d,
						int *range, int not_dest);
void				ft_move_chunck_to_a(t_push_swap_data *d,
						int *range, int not_dest);
void				ft_move_shr_chuncks_to_b(t_push_swap_data *d, \
						size_t chunk_size, int not_dest);
void				ft_move_best_to_b(t_push_swap_data *d, \
						int *range, int not_dest);
void				ft_move_best_to_a(t_push_swap_data *d, \
						int *range, int not_dest);
void				ft_move_chuncks_to_b(t_push_swap_data *d, \
						size_t chunk_size, int not_dest);
void				ft_move_chuncks_to_a(t_push_swap_data *d, \
						size_t chunk_size, int not_dest);
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
int					ft_to_do_when_sorted(t_push_swap_data *d, \
						t_sort_anal *s_anal);

#endif