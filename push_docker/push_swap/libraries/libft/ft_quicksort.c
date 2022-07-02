/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:28:58 by nakawashi         #+#    #+#             */
/*   Updated: 2022/07/01 16:34:14 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_partition(int *i_tab, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = i_tab[high];
	i = (low - 1);
	j = low;
	while (j <= high - 1)
	{
		if (i_tab[j] < pivot)
			ft_swap(&i_tab[++i], &i_tab[j]);
		j++;
	}
	ft_swap(&i_tab[i + 1], &i_tab[high]);
	return (i + 1);
}

static void	ft_recquicksort(int *i_tab, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = ft_partition(i_tab, low, high);
		ft_recquicksort(i_tab, low, pi - 1);
		ft_recquicksort(i_tab, pi + 1, high);
	}
}

void	ft_quicksort(int *i_tab, int size)
{
	ft_recquicksort(i_tab, 0, size - 1);
}
