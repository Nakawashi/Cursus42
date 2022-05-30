/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:07:36 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/30 16:58:15 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// list = stack
// element = element

// is stack empty
int	is_stack_empty(t_elem *head)
{
	if (!head)
		return (1);
	return (0);
}

// read top element


// push (empiler) : ajouter element au sommet
void	push(t_elem **p, t_elem *e)
{
	e->next = *p;
	*p = e;
}

// pop (depiler) : retirer element au sommet
t_elem	*pop(t_elem **p)
{
	t_elem	*e;

	e = NULL;
	if(!is_stack_empty(*p))
	{
		e = *p;
		*p = (*p)->next;
	}
	return (e);
}

// clean stack : desallouer le tout
void	clean_stack(t_elem **p)
{
	t_elem	*e;

	while (!is_stack_empty(*p))
	{
		e = pop(p);
		free(e);
	}
	*p = NULL;
}

