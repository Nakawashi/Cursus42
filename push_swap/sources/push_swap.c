/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:37:32 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/16 00:43:27 by nakawashi        ###   ########.fr       */
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
		printf("element->content: %d\n", *((int *)element->content));
		printf("element->next: %p\n", element->next);
		if (element->next) // si l'élément suivant existe
		{
			if (*((int *)element->content) > *((int *)element->content))
			{
				printf("oulala: %d\n", *((int *)element->content));
			}
		}
		element = element->next; // element++
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
