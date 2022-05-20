/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_building.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:07:36 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/20 16:27:26 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*initialisation()
{
	t_list *liste = malloc(sizeof(*liste));
	t_element *element = malloc(sizeof(*element));

	if (liste == NULL || element == NULL)
	{
		exit(EXIT_FAILURE);
	}

	element->number = 0;
	element->next = NULL;
	liste->actual = element;

	return liste;
}

void insertion(t_list *liste, int nvNombre)
{
    /* Création du nouvel élément */
    t_element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->number = nvNombre;

    /* Insertion de l'élément au début de la liste */
    nouveau->next = liste->actual;
    liste->actual = nouveau;
}