/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:49:38 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/19 17:11:18 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_swap(int *arr, int i, int j)
{
	int	aux;

	aux = arr[i];
	arr[i] = arr[j];
	arr[j] = aux;
}

static int	ft_partition(int *arr, int start, int end)
{
	int	i;
	int	j;
	int	pivot;

	pivot = arr[end];
	i = (start - 1);
	j = start;
	while (j <= end - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			ft_swap(arr, i, j);
		}
		j++;
	}
	ft_swap(arr, i + 1, end);
	return (i + 1);
}

static void	ft_quick_sort(int *arr, int start, int end)
{
	int	p_index;

	if (start < end)
	{
		p_index = ft_partition(arr, start, end);
		ft_quick_sort(arr, start, p_index - 1);
		ft_quick_sort(arr, p_index + 1, end);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	ft_quick_sort(tab, 0, size - 1);
}
