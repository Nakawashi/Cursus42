/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:22:12 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/21 11:54:34 by lgenevey         ###   ########.fr       */
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

	if (from.top == NULL)
		return :
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
