/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log_error_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:57:24 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 23:10:48 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_utils.h>

void	ft_log_err_exit(char *msg, t_push_swap_data **p)
{
	ft_log_error(msg);
	psd_dispose(p);
	exit (-1);
}
