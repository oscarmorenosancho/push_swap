/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:14:08 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/19 17:10:37 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_take_arguments(size_t *size, int argc, char const *argv[])
{
	int	*tab;
	int	i;

	if (argc > 2 && *argv)
	{
		i = 1;
		*size = argc - 1;
		tab = malloc((*size) * sizeof(int));
		while (i < argc)
		{
			tab[i - 1] = ft_atoi(argv[i]);
			i++;
		}
		return (tab);
	}
	*size = 0;
	return (NULL);
}

int	main(int argc, char const *argv[])
{
	int		*tab;
	size_t	size;

	tab = ft_take_arguments(argc, argv, &size);
	ft_sort_int_tab(tab, size);
	return (0);
}
