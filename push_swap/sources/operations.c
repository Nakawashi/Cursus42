/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:24:27 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/19 17:00:59 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* OPERATIONS ALLOWED TO PUSH FROM A STACK TO THE OTHER, AND SWAP NUMBERS */

/*
	swap the first 2 elements of stack a
*/
void	sa(t_stack *stack)
{
	int	temp;

	if (stack && stack->top->next != NULL)
	{
		temp = *((int *)stack->top->content);
		*((int *)stack->top->content) = *((int *)stack->top->next->content);
		*((int *)stack->top->next->content) = temp;
		write(1, "sa\n", 3);
	}
}
