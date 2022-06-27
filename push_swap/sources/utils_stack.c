/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:27:02 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/27 11:46:09 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->size = 0;
	stack->top = NULL;
}

/*
	Fill stack a
	Returns 0 if only 1 number is passed as argument
*/
int	fill_stack(int *num, t_stack *stack)
{
	int		i;
	t_list	*new;

	if (stack->size == 1)
		return (0);
	i = 0;
	while (i < stack->size)
	{
		new = ft_lstnew(&num[i]);
		if (!new)
			return (0);
		ft_lstadd_back(&(stack->top), new);
		i++;
	}
	return (1);
}

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
