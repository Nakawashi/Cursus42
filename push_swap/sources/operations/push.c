/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:22:12 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/20 23:53:54 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	1er élément de la stack en haut de l'autre
	Ajouter le 1er élément de la stack x à la suite des autres de la stack y
*/
static void	push(t_stack *from, t_stack *to)
{
	t_list	*actual_to_top;

	if (!from || !to)
		return ;
	from->size = ft_lstsize(from->top);
	to->size = ft_lstsize(to->top);
	if (to->size) // si deja qqch dans to
		actual_to_top = to->top;
	printf("from initial size : %d\n", from->size);
	printf("to initial size : %d\n", to->size);

	ft_lstadd_front(&(to->top), from->top); // passer de l'un à l'autre

	if (to->size == 0) // si b était vide, le nouvel element est le seul
		to->top->next = NULL;
	else
		to->top->next = actual_to_top;
	from->size -= 1;
	to->size += 1;
	if (from->size > 1)
		from->top = from->top->next; // changer premier élément de from
	else if (from->size == 1)
		from->top->next = NULL;

	printf("numéro passé dans b : %d\n", *((int *)to->top->content));
	printf("nouveau premier élément de a : %d\n", *((int *)from->top->content));
	printf("from size : %d\n", from->size);
	printf("to size : %d\n", to->size);
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
