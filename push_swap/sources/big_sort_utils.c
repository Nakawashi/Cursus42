/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 01:12:43 by nakawashi         #+#    #+#             */
/*   Updated: 2022/07/02 16:24:34 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_template(t_template *template, int size)
{
	template->nb_chunks = get_nb_chunks(size);
	template->nb_values_in_a_chunk = size / template->nb_chunks;
	template->nb_loops = template->nb_chunks - 1;
	template->value_index = (size / template->nb_chunks) - 1;
	template->value_to_compare = 0;
}


