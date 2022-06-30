/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 01:12:43 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/30 20:00:53 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_template(t_template *template, int size, int *num)
{
	int	count;

	template->int_array = (int *)malloc(sizeof(int) * size); // créer tableau meme taille que num
	if (!template->int_array)
		return ;
	count = 0;
	while (count < size)
	{
		template->int_array[count] = num[count];
		++count;
	}
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


