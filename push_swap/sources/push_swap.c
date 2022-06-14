/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:37:32 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/14 18:24:08 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Parcours la stack et retourne 1 si deja triée
	Comparaison entre la valeur courante et la suivante
	S'il existe un element suivant, modifier la valeure courante
*/
int	is_sorted(t_stack *a)
{
	t_list	*element;

	element = a->top;
	while (element) // si element existe
	{
		if (element->next) // tant qu'on n'est pas sur le dernier element
		{
			if (element->content > element->next->content) // element actuel plus grand que le prochain
				return (0);
		}
		element = element->next;
	}
	return (1);
}

void	push_swap(t_stack *a, t_stack *b)
{
	(void) b;

	if (is_sorted(a))
		printf("valeurs dans l'ordre");
	else
		printf("valeurs pas dans l'ordre");
}