/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_n_play_cmd_list_fd.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:49:31 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/28 23:10:48 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_utils.h>

void	ft_read_n_play_cmd_list_fd(t_push_swap_data	*psd, int fd)
{
	char		*line;
	t_stack_cmd	sc;

	if (! psd)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		sc = ft_getstackcmd(line);
		free (line);
		if (sc != nop)
			psd_apply_cmd(psd, sc, 0);
		line = get_next_line(fd);
	}
}
