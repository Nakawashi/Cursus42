/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:17:56 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/25 18:36:03 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Retourne la taille des plages, mais aussi l'index de la valeur
	qui va comparer le reste
	Je préfère avoire des plages plus grandes que de petits chunks
*/
int	get_nb_chunk_necessary(t_stack *a)
{
	if (a->size >= 501)		// si on a 500 nombres ou plus à trier
		return (10);		// nombre par lequel diviser la taille du tableau pour définir la plage de vérification
	if (a->size <= 100)		// si on a 100 nombres ou moins à trier
		return (4);		// nombre par lequel diviser la taille du tableau pour définir la plage de vérification
}

void	big_sort(t_stack *a, t_stack *b)
{
	int	chunks;
	int	current_index;

	chunks = get_nb_chunk_necessary(a);
	while (a->size) //tant qu'il reste qqch dans la stack a
	{
		if ()
	}
}
