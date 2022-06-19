/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:37:32 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/19 15:38:59 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Parcours la stack et retourne 1 si deja triée
	Comparaison entre la valeur courante et la suivante
	Modifier l'adresse sur l'élément courant pour qu'il soit sur le suivant
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
	(void) b;

	if (is_sorted(a))
		printf("valeurs dans l'ordre\n");
	else
		printf("valeurs pas dans l'ordre\n");
}
