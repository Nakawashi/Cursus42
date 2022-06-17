/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:27:02 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/17 14:21:02 by nakawashi        ###   ########.fr       */
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
	printf("num: [%d]\n", num[0]);
	printf("num: [%d]\n", num[1]);
	printf("num: [%d]\n", num[2]);
	printf("num: [%d]\n", num[3]);
	init_stack(stack);
	stack->size = ft_count_indexes(num);
	printf("stack->size : %d\n", stack->size);
	if (stack->size == 1)
		return (0);
	i = 0;
	while(num[i])
	{
		new = ft_lstnew(&num[i]);
		if (!new)
			return (0);
		ft_lstadd_back(&(stack->top), new);
		printf("new->content: %d\n", *((int *)new->content));
		i++;
	}
	return (1);
}
