/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:17:56 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/27 17:12:22 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	retourne l'élément souhaité, à l'emplacement demandé
	utile pour trouver le milieu de la liste
	utile pour trouver le pivot de comparaison
*/
static t_list	*get_element(t_stack *a, int counter)
{
	t_list	*elem;

	elem = a->top;
	while (counter--)
	{
		if (elem == NULL)
			return NULL;
		elem = elem->next;
	}
	return (elem);
}

/*
	Retourne une valeur pas liée au contenu de la pile a
	Définie selon les valeurs min et max de la pile ainsi que du nb à trier
	Utilisé comme comparaison pour le big sort (si plus petit, pb(a, b))
*/
static int	get_pivot_location(t_stack *a)
{
	if (a->size <= 100)
		return (10);
	if (a->size > 100)
		return (11);
	return (-1);
}

/*
	passer les valeurs plus petites que le pivot dans la pile b
	passer les valeurs max de b sur la pile a, ce qui va trier

	a faire : fonction handle a et foncton handle b
*/
void	big_sort(t_stack *a, t_stack *b)
{
	t_list	*middle;
	t_list	*min;
	t_list	*max;
	t_list	*last;
	int		pivot; // sert pour mes pivots
	int		after_middle; // si on passe middle alors = 1 et rra()
	int		size;

	while (a->top && a->size)
	{
		size = a->size;
		after_middle = 0;
		min = get_min_value(a);
		max = get_max_value(a);
		last = ft_lstlast(a->top);
		middle = get_element(a, a->size / 2);
		if (min == NULL || max == NULL || middle == NULL || last == NULL)
			break ;
		pivot = get_content(*min) + ((get_content(*max) - get_content(*min)) / get_pivot_location(a));
		while (size--) //size permet de définir quand s'arrêter
		{
			if (get_content(*last) <= pivot)
				rra(a);
			if (get_content(*a->top) <= pivot)
				pb(a, b); // push sur pile b
			else
				ra(a); // rotate pile a, premier element devient le dernier
		}
	}
	if (TEST)
	{
		printf("size of a : %i\n", a->size);
		printf("size of b : %i\n", b->size);
		print_stack(a, b);
	}
	while (b->size)
	{
		max = get_max_value(b);
		if (max == NULL)
			break ;
		if (get_content(*b->top) == get_content(*max))
			pa(b, a); // push sur pile a
		else
			rb(b);
	}
}
