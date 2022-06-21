/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:22:12 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/21 20:15:45 by lgenevey         ###   ########.fr       */
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


static void	push(t_stack *from, t_stack *to)
{
	t_list	*first_element;

	first_element = from->top; // sauver la premiere adresse
	to->top = from->top;
	from->top = first_element->next;
}

/*
	push element from b to a
*/
void	pa(t_stack *b, t_stack *a)
{
	push(b, a);
	ft_putendl_fd("pa", 1);
}

/*
	push element from a to b
*/
void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_putendl_fd("pb", 1);
}
