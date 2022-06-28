/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:17:56 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/29 00:22:50 by nakawashi        ###   ########.fr       */
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

/* Retourne le nombre de pivots que je veux (chunks) */
static int	get_chunks(t_stack *a)
{
	if (a->size <= 100)
		return (5);
	if (a->size > 100)
		return (11);
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

/*
	Retourne une valeur à ne pas recalculer
	Définie selon les valeurs min et max initiales de la pile
	ainsi que du nb à trier
	Utilisé comme comparaison pour le big sort (si plus petit, pb(a, b))
	Ma façon de couper en n parties égales
*/
static int	get_additionner(t_stack *a, int min, int max)
{
	if (a->size <= 100)
		return ((max - min) / get_chunks(a));
	if (a->size > 100)
		return ((max - min) / get_chunks(a));
	return (-1);
}

/*
	on stack a
*/
static void	lst_swap_move_big(t_stack *a)
{
	t_list	*elem;
	t_list	*next;

	elem = a->top;
	next = elem->next;
	if (get_content(*elem) > get_content(*elem->next))
		sa(a);
}

void	bubble_sort(t_stack *a)
{
	int	i;
	int	size;

	size = a->size - 1;
	while (is_sorted(a) != 1)
	{
		i = 0;
		while (i < size)
		{
			lst_swap_move_big(a);
			ra(a);
			i++;
		}
		i = 0;
		while (i < size)
		{
			rra(a);
			lst_swap_move_small(a);
			i++;
		}
		--size;
	}
}

/*
	Sorte de Quicksort
	Calculer mes pivots
	passer les éléments plus petit que lui sur b
*/
static void	handle_stack_a(t_stack *a, t_stack *b)
{
	t_list	*min;
	t_list	*max;
	int		fix_value;
	int		pivot; // sert pour mes pivots
	int		nb_of_handshakes;

	min = get_min_value(a);
	max = get_max_value(a);
	fix_value = get_additionner(a, get_content(*min), get_content(*max));
	pivot = get_content(*min) + fix_value;

	while (pivot < get_content(*max) - fix_value)
	{
		nb_of_handshakes = ft_lstsize(a->top);
		min = get_min_value(a);
		max = get_max_value(a);
		if (min == NULL || max == NULL)
			return ;
		while (nb_of_handshakes--) // parcourir qu'une une fois chaque élément
		{
			if (get_content(*a->top) <= pivot)
				pb(a, b);
			else
				ra(a);
		}
		pivot = pivot + fix_value;
	}
}

// faire arriver à top la prochaine valeur max
// parcourir b et trouver le nombre de moves à faire avant de tomber sur max
// si plus petit que pour arriver à mid, rb()
// sinon rrb() (moins de mouvements à faire depuis le bas)
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
			pa(b, a);
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
	bubble_sort(a);
	handle_stack_b(a, b);
}
