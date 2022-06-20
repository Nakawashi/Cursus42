/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:43:45 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/20 13:14:46 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Update next address that link each element
*/
static void	reverse_rotate(t_stack *stack)
{
	t_list	*actual_last;
	t_list	*actual_first;
	t_list	*actual_second_last;

	if (!stack)
		return ;
	actual_last = ft_lstlast(stack->top);
	actual_first = stack->top;
	while (stack->top->next != NULL)
	{
		actual_second_last = stack->top;
		stack->top = stack->top->next;
	}
	stack->top = actual_last;
	actual_last->next = actual_first;
	actual_second_last->next = NULL;
}

/*
	reverse_rotate a, shift down all elements of stack a by 1.
	the last element becomes the first one.
*/
void	rra(t_stack *stack)
{
	reverse_rotate(stack);
	ft_putendl_fd("rra", 1);
}
