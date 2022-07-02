/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:27:02 by lgenevey          #+#    #+#             */
/*   Updated: 2022/07/02 11:29:48 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->size = 0;
	stack->top = NULL;
}

/*
	Parce que c'est relou de cast tout le temps
*/
int	get_content(t_list list)
{
	return (*((int *)list.content));
}

/*
	return the min value in stack a
*/
t_list	*get_min_value(t_stack *stack)
{
	t_list	*elem;
	t_list	*min;

	elem = stack->top;
	if (elem == NULL)
		return (NULL);
	min = elem;
	while (elem)
	{
		if (get_content(*min) > get_content(*elem))
			min = elem;
		elem = elem->next;
	}
	return (min);
}

t_list	*get_max_value(t_stack *stack)
{
	t_list	*elem;
	t_list	*max;

	elem = stack->top;
	if (elem == NULL)
		return (NULL);
	max = elem;
	while (elem)
	{
		if (get_content(*max) < get_content(*elem))
			max = elem;
		elem = elem->next;
	}
	return (max);
}
