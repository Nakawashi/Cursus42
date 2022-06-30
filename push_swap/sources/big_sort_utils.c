/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 01:12:43 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/30 15:11:45 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_template(t_template *template, t_stack *a, int *n)
{
	template->int_array = n;
	template->int_array_size = a->size;
	int i = 0;
	while (i < a->size)
	{
		printf("AVANT n[%i] = [%d]\n", i, n[i]);
		++i;
	}
	ft_quicksort(n, a->size);
	i = 0;
	while (i < a->size)
	{
		printf("APRES n[%i] = [%d]\n", i, n[i]);
		++i;
	}
	template->nb_chunks = get_nb_chunks(a);
	template->nb_values_in_a_chunk = a->size / template->nb_chunks;
	template->nb_loops = template->nb_chunks - 1;
	template->value_index = (a->size / template->nb_chunks) - 1;
	template->pivot_value = template->int_array[template->value_index];
}
