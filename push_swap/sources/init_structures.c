/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:34:42 by nakawashi         #+#    #+#             */
/*   Updated: 2022/05/28 14:47:10 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack *init_stack(void)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->first = NULL;
	stack->last = NULL;
	return (stack);
}

t_book *init_book(void)
{
	t_book *element;

	element = (t_book *)malloc(sizeof(t_book));
	if (!element)
		return (NULL);
	element->data = 0;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}
