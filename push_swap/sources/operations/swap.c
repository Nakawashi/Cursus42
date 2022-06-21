/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:00:31 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/21 13:26:48 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


/*
	if stack empty OR first element smaller then the second, do nothing
*/
static void	swap(t_stack *stack)
{
	int	temp;

	if (stack || *((int *)stack->top->content) > *((int *)stack->top->next->content))
	{
		temp = *((int *)stack->top->content);
		*((int *)stack->top->content) = *((int *)stack->top->next->content);
		*((int *)stack->top->next->content) = temp;
	}
}

/*
	swap the first 2 elements of stack a
*/
void	sa(t_stack *stack)
{
	swap(stack);
	ft_putendl_fd("sa", 1);
}

/*
	swap the first 2 elements of stack b
*/
void	sb(t_stack *stack)
{
	swap(stack);
	ft_putendl_fd("sb", 1);
}

/*
	swap the first 2 elements of stack a
	swap the first 2 elements of stack b
*/
void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	ft_putendl_fd("ss", 1);
}
