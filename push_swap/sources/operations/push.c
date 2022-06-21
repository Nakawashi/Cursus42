/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:22:12 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/21 23:12:03 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	1er élément de la stack en haut de l'autre
	Ajouter le 1er élément de la stack x à la suite des autres de la stack y
*/
// static void	push(t_stack *from, t_stack *to)
// {
// 	t_list	*first_element;
// 	t_list	*last_element;

// 	first_element = from->top;
// 	last_element = ft_lstlast(from->top);
// 	if (!from->top->next)
// 	{
// 		from->top = 0;
// 		last_element = 0;
// 	}
// 	else
// 	{
// 		from->top = from->top->next;
// 	}
// 	first_element->next = 0;
// 	ft_lstadd_front(&(to->top), first_element);
// 	from->size--;
// }


static void	push_b(t_stack *from, t_stack *to)
{
	t_list	*first_element;

	printf("FROM size : 	[%i]\n", from->size);
	printf("TO size : 	[%i]\n", to->size);

	first_element = NULL; // sauver la premiere adresse

	if (from->top)
	{
		first_element = from->top; // sauver la premiere adresse
		to->top = first_element;
		from->top = from->top->next;
		to->size++;
		from->size--;
	}

	printf("FROM size AFTER : 	[%i]\n", from->size);
	printf("TO size AFTER:	 	[%i]\n", to->size);

}

/*
	push element from b to a
*/
void	pa(t_stack *b, t_stack *a)
{
	push_b(b, a);
	ft_putendl_fd("pa", 1);
}

/*
	push element from a to b
*/
void	pb(t_stack *a, t_stack *b)
{
	push_b(a, b);
	ft_putendl_fd("pb", 1);
}
