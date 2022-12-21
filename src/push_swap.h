/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:12:35 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/21 13:24:36 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "../src_utils/push_swap_utils.h"

typedef struct s_prog_data
{
	int			*tab;
	int			*sorted;
	size_t		size;
	t_dllist	*stack_a;
	t_dllist	*stack_b;
}	t_prog_data;

#endif