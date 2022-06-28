/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:17:56 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/28 02:00:54 by nakawashi        ###   ########.fr       */
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
	Ma façon de couper en n parties égales proche de min.
*/
static int	get_pivot_location(t_stack *a, int min, int max)
{
	if (a->size <= 100)
		return (min + (max - min) / 5);
	if (a->size > 100)
		return (min + (max - min) / 11);
	return (-1);
}

/*
	Retourne le nombre de steps à faire depuis en haut pour arriver
	à l'élément souhaité (middle, max...)
*/
static int	count_steps_before_element(t_stack *stack, t_list *element)
{
	int		i;
	t_list	*elem;


	i = 0;
	elem = stack->top;
	while (elem)
	{
		if (get_content(*elem) == get_content(*element))
		return (i);
		++i;
		elem = elem->next;
	}
	return (i);
}

static void	handle_stack_a(t_stack *a, t_stack *b)
{
	t_list	*min;
	t_list	*max;
	int		pivot; // sert pour mes pivots
	int		size;

	min = NULL;
	max = NULL;
	while (a->size)
	{
		min = get_min_value(a);
		max = get_max_value(a);
		if (min == NULL || max == NULL)
			return ;
		pivot = get_pivot_location(a, get_content(*min), get_content(*max));
		size = ft_lstsize(a->top);
		while (size--) // parcourir une fois chaque élément
		{
			if (get_content(*a->top) <= pivot) //compare chaque élément ave le pivot
				pb(a, b);
			else
				ra(a);
		}
	}
}
// je veux faire arriver à top la prochaine valeur max
// parcourir b, retourner le nombre de mouvements pour y arriver
// si plus petit que pour arriver à mid, ra
// sinon rra ca sera plus court s'il est en bas


static void	handle_stack_b(t_stack *a, t_stack *b)
{
	t_list	*max;
	t_list	*middle;
	int		moves_to_middle;
	int		moves_to_max;

	middle = get_element(b, b->size / 2);
	if (middle == NULL)
			return ;
	while (b->size)
	{
		max = get_max_value(b);
		if (max == NULL)
			break ;
		moves_to_middle = count_steps_before_element(b, middle);
		moves_to_max = count_steps_before_element(b, max);
		if (get_content(*b->top) == get_content(*max))
			pa(b, a); // push sur pile a
		else if (moves_to_max < moves_to_middle)
			rb(b);
		else
			rrb(b);
	}
}

/*
	passer les valeurs plus petites que le pivot dans la pile b
	bubble sort si besoin sur toute la stack
	check par rapport au milieu si ra ou rra
	passer les valeurs max de b sur la pile a, ce qui va trier

	a faire : fonction handle a et foncton handle b
*/
void	big_sort(t_stack *a, t_stack *b)
{
	handle_stack_a(a, b);
	while (b->top) // mon bubble sort
	{
		sb(b);
		printf("bubble sort: [%d]\n", get_content(*b->top));
		b->top = b->top->next;
	}
	if (TEST)
	{
		print_stack(a, b);
	}
	handle_stack_b(a, b);
}
