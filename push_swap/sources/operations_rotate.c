/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:45:16 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/20 12:05:09 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Update next address that link each element
*/
static void	rotate(t_stack *stack)
{
	t_list	*actual_last;
	t_list	*actual_first;

	actual_last = ft_lstlast(stack->top);
	actual_first = stack->top;

	printf("actual last : %d\n", *((int *)actual_last->content));
	printf("actual first : %d\n", *((int *)actual_first->content));

	actual_last->next = actual_first->next;
	actual_first->next = NULL;

	printf("last : %d\n", *((int *)actual_last->content));
	printf("first : %d\n", *((int *)actual_first->content));
}

/*
	rotate a, shift up all elements of stack a by 1.
	the first element becomes the last one. the second element is now 1st.
*/
void	ra(t_stack *stack)
{
	rotate(stack);
	ft_putendl_fd("ra", 1);
}
