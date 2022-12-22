/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:53:12 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/22 13:20:39 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	*ft_take_arguments(t_push_swap_data **p, \
						int argc, char const *argv[])
{
	int	*tab;
	int	i;
	int	nbr;
	int	ok;

	if (argc > 1 && *argv && p)
	{
		i = 1;
		(*p)->size = argc - 1;
		tab = malloc((*p)->size * sizeof(int));
		if (! tab)
			ft_log_err_exit("malloc failed to allocate memory\n", p);
		ok = 1;
		while (i < argc && tab && ok)
		{
			ok = ft_check_n_get_argument(argv[i], &nbr);
			if (! ok)
				ft_log_err_exit("All arg. must be integer dec. numbers\n", p);
			tab[i - 1] = nbr;
			i++;
		}
		return (tab);
	}
	ft_log_err_exit("Not enough arguments were provided\n", p);
	return (NULL);
}
