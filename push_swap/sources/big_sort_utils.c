/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 01:12:43 by nakawashi         #+#    #+#             */
/*   Updated: 2022/07/01 01:46:04 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_template(t_template *template, int size)
{
	int i = 0;
	while (i < size)
	{
		printf("AVANT quicksort n[%i] = [%d]\n", i, template->int_array[i]);
		++i;
	}
	printf("\n");
	ft_quicksort(template->int_array, size);
	i = 0;
	while (i < size)
	{
		printf("APRES quicksort n[%i] = [%d]\n", i, template->int_array[i]);
		++i;
	}
	template->nb_chunks = get_nb_chunks(size);
	template->nb_values_in_a_chunk = size / template->nb_chunks;
	template->nb_loops = template->nb_chunks - 1;
	template->value_index = (size / template->nb_chunks) - 1;
	template->value_to_compare = template->int_array[template->value_index];
}


