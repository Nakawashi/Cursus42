/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:22:12 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/21 13:42:46 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	1er élément de la stack en haut de l'autre
	Ajouter le 1er élément de la stack x à la suite des autres de la stack y
*/
static void	push(t_stack *from, t_stack *to)
{
	t_list	*first_element;

	first_element = NULL;
	if (from->top != NULL)
	{
		first_element = from->top; // sauver la premiere adresse si elle existe
		to->top = from->top; // faire pointer to sur la premiere adresse aussi
	}
	if (from->top->next != NULL)
		from->top = first_element->next; // faire pointer from sur la seconde adresse
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
