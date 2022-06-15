/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:37:32 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/15 23:37:07 by nakawashi        ###   ########.fr       */
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
	while (element) // tant que l'element existe
	{
		printf("coucou\n");
		if (element->next) // si l'élément suivant existe
		{
			printf("coucou2\n");
			if (element->content > element->next->content) // element actuel plus grand que le prochain
			printf("oulala\n");
		}
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
