/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:14:08 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/20 13:35:00 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_n_get_argument(const char *s, int *nbr)
{
	char	*clone;
	int		res;

	if (! s || ! s[0])
		return (0);
	if (s[0] == '+')
		s++;
	*nbr = ft_atoi(s);
	clone = ft_itoa(*nbr);
	res = ! ft_strncmp(s, clone, 20);
	free_x ((void **)&clone);
	return (res);
}

static void	ft_log_err_exit(char *msg, int **p)
{
	ft_log_error(msg);
	free_x ((void **)p);
	exit (-1);
}

static int	*ft_take_arguments(size_t *size, int argc, char const *argv[])
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
				ft_log_err_exit("All arguments must be decimal numbers\n", &tab);
			tab[i - 1] = nbr;
			i++;
		}
		return (tab);
	}
	ft_log_err_exit("Not enough arguments were provided\n", &tab);
	return (NULL);
}

int	main(int argc, char const *argv[])
{
	int					*tab;
	int					*sorted;
	size_t				size;
	unsigned int		i;

	tab = ft_take_arguments(&size, argc, argv);
	if (tab)
	{
		ft_sort_int_tab(tab, size);
		sorted = ft_clone_int_tab(tab, size);
		if (! sorted)
			ft_log_err_exit("malloc failed when alocating memory\n", &tab);
		if (ft_check_duplicated(sorted, size))
		{
			free_x((void **)&sorted);
			free_x((void **)&tab);
			exit (-1);
		}
		i = 0;
		while (tab && i < size)
		{
			ft_putnbr_fd(tab[i++], 1);
			ft_putchar_fd('\n', 1);
		}
		free_x((void **)&sorted);
		free_x((void **)&tab);
	}
	return (0);
}
