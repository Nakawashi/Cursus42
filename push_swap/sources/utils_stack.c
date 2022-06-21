/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:27:02 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/21 15:51:15 by lgenevey         ###   ########.fr       */
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
	while(i < stack->size)
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
t_list	*get_greatest_element(t_stack *a)
{
	t_list	*greatest;

	greatest = a->top;
	while (a->top->next != NULL)
	{
		if (*((int *)greatest->content) < *((int *)a->top->next->content))
			greatest = a->top;
		a->top = a->top->next;
	}
	printf("greatest: [%d]\n", *((int *)greatest->content));
	return (greatest);
}

/*
	return the address of the element that contains the second greatest INT val
*/
t_list	*get_second_last_greatest_element(t_stack *a)
{
	t_list	*second_greatest;

	second_greatest = a->top;
	while (a->top->next != NULL)
	{
		if (*((int *)second_greatest->content) < *((int *)a->top->next->content))
			second_greatest = a->top;
		a->top = a->top->next;
	}
	printf("greatest: [%d]\n", *((int *)second_greatest->content));
	return (second_greatest);
}
