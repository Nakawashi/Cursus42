/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:13:10 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/21 15:49:20 by lgenevey         ###   ########.fr       */
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
	prend les deux valeeurs les plus grandes, les mets a l'ecart
	trie les trois qui restent
	ramene les deux ensuite
*/
void	sort_5_elements(t_stack *a, t_stack *b)
{
	(void) a;
	(void) b;
	t_list	*max;
	t_list	*second_max;

	max = get_greatest_element(a);

}
