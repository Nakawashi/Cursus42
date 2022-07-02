/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:17:56 by nakawashi         #+#    #+#             */
/*   Updated: 2022/07/02 16:33:28 by lgenevey         ###   ########.fr       */
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

int	get_nb_chunks(int size)
{
	if (size <= 100)
		return (5);
	if (size > 100 && size <= 400)
		return (10);
	if (size > 400)
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


static int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
/*
	Sorte de Quicksort / divide and conquer
	- Comparer si valeur plus petite, passer à b
	Puis rappatrier b avec un tri par séléction
	nb_of_handshakes : pour ne parcourir qu'une une fois chaque élément
*/
static void	handle_stack_a(t_stack *a, t_stack *b, t_template *template)
{
	t_list	*max;
	int		nb_of_handshakes;

	max = ft_lstlast(a->top);
	if (max == NULL)
		return ;
	init_template(template, a->size);
	ft_quicksort(template->int_array, a->size);
	template->value_to_compare = template->int_array[template->value_index];
	while (a->size)
	{
		nb_of_handshakes = a->size;
		while (nb_of_handshakes--)
		{
			if (get_content(*a->top) <= template->value_to_compare){
				pb(a, b);
			}
			else
				ra(a);
		}
		a->size = ft_lstsize(a->top);
		template->value_index += min(template->nb_values_in_a_chunk, a->size);
		template->value_to_compare = template->int_array[template->value_index];
		if (a->size == 3)
		{
			sort_3_elements(a);
			return ;
		}
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
	t_list	*last;
	int		moves_to_middle;
	int		moves_to_max;

	while (b->size)
	{
		max = get_max_value(b);
		middle = get_element(b, b->size / 2);
		last = ft_lstlast(b->top);
		if (max == NULL || middle == NULL || last == NULL)
			break ;
		moves_to_middle = count_steps_before_element(b, middle);
		moves_to_max = count_steps_before_element(b, max);
		if ((get_content(*last) == get_content(*max)) && b->size > 3)
			rrb(b);
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
	check par rapport au milieu si ra ou rra
	passer les valeurs max de b sur la pile a, ce qui va trier

	a faire : fonction handle a et foncton handle b
*/
void	big_sort(t_stack *a, t_stack *b, t_template *template)
{
	handle_stack_a(a, b, template);
	handle_stack_b(a, b);
}
