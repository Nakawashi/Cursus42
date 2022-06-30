/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:17:56 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/30 15:21:24 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	retourne l'élément souhaité, à l'emplacement demandé
	utile pour trouver le milieu de la liste
	utile pour trouver le pivot de comparaison
*/
static t_list	*get_element(t_stack *a, int location)
{
	t_list	*elem;

	elem = a->top;
	while (location--)
	{
		if (elem == NULL)
			return NULL;
		elem = elem->next;
	}
	return (elem);
}

// taille de la stack
// faire un tableau
// insérer la liste dans le tableau modèle
// chemin le plus court et de définir les chunks (je sais que le 20eme)
/* Retourne le nombre de pivots que je veux (chunks) */

void	get_shortest_path();



int	get_nb_chunks(t_stack *a)
{
	if (a->size <= 100)
		return (5);
	if (a->size > 100)
		return (12);
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
	Les éléments les plus grands en bas
*/
void	bubble_sort(t_stack *stack)
{
	t_list	*element;

	while (is_sorted(stack) == 0)
	{
		element = stack->top;
		while (element && element->next)
		{
			if (get_content(*element) > get_content(*element->next))
				sa(stack);
			element = element->next;
		}
	}
}


/*
	Sorte de Quicksort
	- Comparer si valeur plus petite, passer à b
	Laisser le dernier chunk dans a, bubble sort dessus
	Puis rappatrier b avec un tri par séléction
	nb_of_handshakes : pour ne parcourir qu'une une fois chaque élément
*/
static void	handle_stack_a(t_stack *a, t_stack *b, t_template *template)
{
	t_list	*last;
	int		nb_of_handshakes;
	int		i;

	last = ft_lstlast(a->top);
	i = 0;
	while (i < template->nb_loops)
	{
		nb_of_handshakes = ft_lstsize(a->top);
		while (nb_of_handshakes--)
		{
			if (get_content(*last) <= template->pivot_value)
				rra(a);
			if (get_content(*a->top) <= template->pivot_value)
				pb(a, b);
			else
				ra(a);
		}
		template->value_index += template->nb_values_in_a_chunk;
		++i;
	}
}

/*
	Tri par séléction
	Chemin le plus court : si élément voulu = avant le milieu : ra() sinon rra()
*/
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
void	big_sort(t_stack *a, t_stack *b, t_template *template)
{
	handle_stack_a(a, b, template);
	handle_stack_b(a, b);
}
