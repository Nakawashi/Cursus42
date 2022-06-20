/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:13:10 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/20 12:01:54 by nakawashi        ###   ########.fr       */
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
	if (mid < top && top < bot) //case 1
		sa(a);
	if (top < mid && top > bot) //case 5
		sa(a);//rra(a)
	if (top > mid && top > bot && mid < bot) //case 3
		ra(a);
	if (top > mid && mid > bot) // case 2
	{
		sa(a);
		//rra
	}
	if (top < mid && mid > bot) // case 4
	{
		sa(a);
		ra(a);
	}
}
