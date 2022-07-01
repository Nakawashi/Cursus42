/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:17:56 by nakawashi         #+#    #+#             */
/*   Updated: 2022/07/01 15:37:38 by nakawashi        ###   ########.fr       */
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
	if (size > 100)
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
void	bubble_sort(t_stack *stack, int size)
{
	t_list	*element;

	if (size == 3)
		sort_3_elements(stack);
	if (size == 2)
		sort_2_elements(stack);
	while (is_sorted(stack) == 0)
	{
		element = stack->top;
		while (get_content(*element) > get_content(*element->next) && element->next)
		{
			sa(stack);
			ra(stack);
		}
	}
}

/*
	Sorte de Quicksort / divide and conquer
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
	init_template(template, a->size);
	ft_quicksort(template->int_array, a->size);
	template->value_to_compare = template->int_array[template->value_index];
	printf("a.size : %d\n", a->size);
	printf("template->nb_loops : %d\n", template->nb_loops);
	printf("template->nb_chunks : %d\n", template->nb_chunks);
	printf("template->nb_values_in_a_chunk : %d\n", template->nb_values_in_a_chunk);
	printf("template->value_index : %d\n", template->value_index);

	if (TEST)
	{
		int j = 0;
		while (j < a->size)
		{
			printf("---> template->int_array i : %d\n", template->int_array[j]);
			j++;
		}
		printf("\n");

		printf("^ avant de commencer à trier ^\n\n");
	}
	i = 0;
	while (i < a->size)
	{
		printf("template->value_to_compare : %d\n", template->value_to_compare);
		nb_of_handshakes = ft_lstsize(a->top);
		while (nb_of_handshakes--)
		{
			if (TEST)
				printf("int_array[%i] = %d\n",template->value_index, template->int_array[template->value_index]);
			if (get_content(*last) <= template->value_to_compare)
				rra(a);
			if (get_content(*a->top) <= template->value_to_compare)
				pb(a, b);
			else
				ra(a);
		}
		template->value_index += template->nb_values_in_a_chunk;
		template->value_to_compare = template->int_array[template->value_index];
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
/* 		if (TEST)
		{
			printf("max : %d\n", get_content(*max));
			printf("middle : %d\n", get_content(*middle));
			printf("moves to middle : %d\n", moves_to_middle);
			printf("moves to max : %d\n", moves_to_max);
			print_stack(a, b);
		} */
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
	bubble sort si besoin sur toute la stack
	check par rapport au milieu si ra ou rra
	passer les valeurs max de b sur la pile a, ce qui va trier

	a faire : fonction handle a et foncton handle b
*/
void	big_sort(t_stack *a, t_stack *b, t_template *template)
{
	handle_stack_a(a, b, template);
	//bubble_sort(a, a->size);
	handle_stack_b(a, b);
}
