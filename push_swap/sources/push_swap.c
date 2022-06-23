/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:37:32 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/23 20:59:08 by lgenevey         ###   ########.fr       */
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
		return ;
	if (a->size == 2)
		sort_2_elements(a);
	else if (a->size == 3)
		sort_3_elements(a);
	else if (a->size == 5)
		sort_5_elements(a, b);
	else
		sort_big(a, b);
}
