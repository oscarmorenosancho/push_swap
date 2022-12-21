/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:53:12 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/21 09:52:48 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	*ft_take_arguments(size_t *size, int argc, char const *argv[])
{
	int	*tab;
	int	i;
	int	nbr;
	int	ok;

	if (argc > 1 && *argv)
	{
		i = 1;
		*size = argc - 1;
		tab = malloc((*size) * sizeof(int));
		if (! tab)
			ft_log_err_exit("malloc failed to allocate memory\n", &tab);
		ok = 1;
		while (i < argc && tab && ok)
		{
			ok = ft_check_n_get_argument(argv[i], &nbr);
			if (! ok)
				ft_log_err_exit("All arg. must be integer dec. numbers\n", &tab);
			tab[i - 1] = nbr;
			i++;
		}
		return (tab);
	}
	ft_log_err_exit("Not enough arguments were provided\n", &tab);
	return (NULL);
}
