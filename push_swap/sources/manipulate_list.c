/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:07:36 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/28 14:59:05 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// list = stack
// element = element

// creates and add new element in stack
void	add_elem_at_top(t_stack *stack, int number)
{
	t_book *new = (t_book *)malloc(sizeof(*new));
	if (stack == NULL || new == NULL)
		ft_printf("erreur, quitter");
}

