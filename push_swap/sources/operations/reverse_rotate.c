/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:43:45 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/27 18:16:46 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Update next address that link each element
	The last element becomes the first one.
*/
static void	reverse_rotate(t_stack *stack)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*second_last;

	if (stack->top == NULL)
		return ;
	tmp = stack->top;
	stack->top = stack->top->next;
	while (tmp)
	{
		if (tmp->next == NULL)
			second_last = tmp;
		last = tmp;
		tmp = tmp->next;
	}


}

/*
	shift down
*/
void	rra(t_stack *stack)
{
	reverse_rotate(stack);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *stack)
{
	reverse_rotate(stack);
	ft_putendl_fd("rrb", 1);
}
