/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:37:32 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/22 21:02:57 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Parcours la liste chainée et retourne 1 si deja triée
	Comparaison entre la valeur courante et la suivante
	Aller à l'élément suivant de la liste chainée
*/
int	is_sorted(t_stack *stack)
{
	t_list	*element;

	element = stack->top;
	while (element && element->next)
	{
		if (*((int *)element->content) > *((int *)element->next->content))
			return (0);
		element = element->next;
	}
	return (1);
}

void	push_swap(t_stack *a, t_stack *b)
{
	int	compter;

	compter = 0;
	if (is_sorted(a))
	{
		printf("is sorted : free num, liste et array si argc == 2\n");
		return ;
	}
	if (a->size == 2)
		sort_2_elements(a);
	else if (a->size == 3)
		sort_3_elements(a);
	else if (a->size == 5)
		sort_5_elements(a, b);
}
