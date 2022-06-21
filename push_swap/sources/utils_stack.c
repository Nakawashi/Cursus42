/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:27:02 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/21 16:58:18 by lgenevey         ###   ########.fr       */
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

	init_stack(stack);
	stack->size = ft_count_indexes(num);
	if (stack->size == 1)
		return (0);
	i = 0;
	while (i < stack->size)
	{
		new = ft_lstnew(&num[i]);
		if (!new)
			return (0);
		ft_lstadd_back(&(stack->top), new);
		printf("fill_stack:	[%d]\n", *(int *)new->content);
		i++;
	}
	return (1);
}

/*
	return the address of the element that contains the greatest INT value
*/
int	get_min_value(t_stack *a)
{
	t_list	*elem;
	int		min;

	elem = a->top;
	min = *((int *)elem->content);
	while (elem->next != NULL)
	{
		if (min > *((int *)elem->next->content))
			min = *((int *)elem->next->content);
		elem = elem->next;
	}
	return (min);
}

/*
	return the address of the element that contains the second greatest INT val
*/

