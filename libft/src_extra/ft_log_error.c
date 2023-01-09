/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:46:13 by omoreno-          #+#    #+#             */
/*   Updated: 2023/01/09 15:36:21 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

int	ft_log_error_msg(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	return (0);
}

int	ft_log_error(char *msg)
{
	(void)msg;
	ft_putstr_fd("Error\n", 2);
	return (0);
}
