/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:27:02 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/16 00:44:05 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->size = 0;
	stack->top = NULL;
}

/*
	convert char to int
	Fill stack a
	Returns 0 if only 1 number is passed as argument
*/
int	fill_stack(char **array, t_stack *stack)
{
	int		i;
	int		*num;
	t_list	*new;

	init_stack(stack);
	stack->size = ft_strlen_arrays(array);
	if (stack->size == 1)
		return (0);
	i = 0;
	while(array[i])
	{
		num = malloc(sizeof(int));
		if (!num)
			return (0);
		num[i] = ft_atoi(array[i]);
		printf("[%d]\n", num[i]);
		new = ft_lstnew(num);
		if (!new)
			return (0);
		ft_lstadd_back(&(stack->top), new);
		printf("new->content: %d\n", *((int *)new->content));
		i++;
	}
	return (1);
}
