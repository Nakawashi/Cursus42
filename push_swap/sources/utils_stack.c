/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:27:02 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/14 14:57:50 by lgenevey         ###   ########.fr       */
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
*/
int	fill_stack(char **array, t_stack *stack)
{
	int *num;
	t_list *n;

	init_stack(stack);
	stack->size = ft_strlen_arrays(array);
	while(array){
		num = malloc(sizeof(int));
		if (!num)
			return (1);
		*num = ft_atoi(*array);
		n = ft_lstnew(num);
		if (!n)
			return (1);
		ft_lstadd_back(&(stack->top), n);
		array++;
	}
}