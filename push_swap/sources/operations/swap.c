/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:00:31 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/28 01:57:45 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	if stack empty OR first element smaller then the second, do nothing
*/
static void	swap(t_stack *stack)
{
	int	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top->content;
	stack->top->content = stack->top->next->content;
	stack->top->next->content = tmp;
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
