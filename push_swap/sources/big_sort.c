/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:17:56 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/26 13:23:46 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Retourne le contenu de l'élément qui se trouve au milieu de la liste
	Permettra de savoir s'il vaut mieux ra que rra
	ra : si en haut de la liste (index de la valeur plus petit que le milieu)
	rra : si en bas de la liste (index de la valeur plus grand que le milieu)
	exemple impair : si size = 11, central index vaudra 5
*/
static int	get_middle(t_stack *a)
{
	t_list	*element;
	int		middle;

	element = a->top;
	middle = a->size / 2;
	while (middle--)
		element = element->next;
	return (*((int *)element->content));
}

/*
	Retourne l'index du pivot, selon le nombre de valeurs à trier
	on comparera les valeurs au pivot pour les basculer à b si plus petites
*/
static int	get_pivot(t_stack *a)
{
	if (a->size <= 100)				// si on a 100 nombres ou moins
		return (a->size / 4);		// nombre par lequel diviser la taille du tableau pour définir la plage de vérification
	if (a->size > 100)
		return (a->size / 10);
	return (-1);
}

void	big_sort(t_stack *a, t_stack *b)
{
	t_list	*elem;
	int		middle;
	int		pivot;
	(void) b;

	elem = a->top;
	middle = get_middle(a);
	pivot = get_pivot(a);
	while (elem) // on parcours la liste en entiers, dernier élément inclus
	{
		printf("hello\n");
		elem = elem->next;
	}
}
