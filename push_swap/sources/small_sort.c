/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:13:10 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/27 11:46:31 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 2, 3. 4 OR 5 NUMBERS TO SORT */

void	sort_2_elements(t_stack *a)
{
	sa(a);
}

void	sort_3_elements(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = *((int *)a->top->content);
	mid = *((int *)a->top->next->content);
	bot = *((int *)ft_lstlast(a->top)->content);
	if (mid < top && top < bot)
		sa(a);
	else if (top < mid && top > bot)
		rra(a);
	else if (top > mid && top > bot && mid < bot)
		ra(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top < mid && mid > bot)
	{
		sa(a);
		ra(a);
	}
}

/*
	Separe les deux valeurs plus petites
	Trier les trois valeurs restantes
*/
void	sort_5_elements(t_stack *a, t_stack *b)
{
	t_list	*min;
	t_list	*last;

	while (a->size > 3)
	{
		min = get_min_value(a);
		last = ft_lstlast(a->top);
		if (get_content(*last) == get_content(*min))
			rra(a);
		if (get_content(*a->top) == get_content(*min))
			pb(a, b);
		else
			ra(a);
	}
	sort_3_elements(a);
	while (b->size)
		pa(b, a);
}
