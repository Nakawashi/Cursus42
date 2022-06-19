/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:45:16 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/19 20:40:44 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Update next address which link each element
*/
static void	rotate(t_stack *stack)
{
	ft_lstlast(stack->top)->next = stack->top;
	stack->top->next = NULL;


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
