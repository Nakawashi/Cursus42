/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:13:10 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/21 19:41:13 by lgenevey         ###   ########.fr       */
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
	int	min;
	int	last;

	last = *((int *)(ft_lstlast(a->top))->content);
	while (a->size > 3)
	{
		min = get_min_value(a);
		if (last == min)
			ra(a);
		if (*((int *)a->top->content) == min)
			pb(a, b);
		else
			ra(a);
	}
	sort_3_elements(a);
	while (b->size)
		pa(b, a);
}
