/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:17:56 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/25 23:17:44 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Récupère l'index central selon le nombre de valeurs à trier
	Permettra de savoir s'il vaut mieux ra que rra
	ra : si en haut de la liste (index de la valeur plus petit que le milieu)
	rra : si en bas de la liste (index de la valeur plus grand que le milieu)
	si size = 11, central index vaudra 5
*/
static int	get_central_index(t_stack *a)
{
	return (a->size / 2);
}

/*
	Retourne l'index du pivot, selon le nombre de valeurs à trier
*/
static int	get_pivot_index(t_stack *a)
{
	if (a->size <= 100)				// si on a 500 nombres ou moins
		return (a->size / 5);		// nombre par lequel diviser la taille du tableau pour définir la plage de vérification
	if (a->size <= 500)				// si on a 100 nombres ou moins à trier
		return (a->size / 10);		// nombre par lequel diviser la taille du tableau pour définir la plage de vérification
	return (-1);
}

void	big_sort(t_stack *a, t_stack *b)
{
	t_list	*elem;
	int	central_index;
	int	pivot_index;
	(void) b;

	elem = a->top;
	central_index = get_central_index(a);
	pivot_index = get_pivot_index(a);
	printf("hello\n", *(int *)elem->index->content);
	while (elem) // on parcours la liste
	{

		printf("hello\n");
		elem = elem->next;
	}
}
