/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:35:24 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/23 21:10:25 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compute_chunk_pieces(int size)
{
	if (size >= 500)
		return (8);
	if (size >= 400)
		return (7);
	if (size >= 300)
		return (6);
	if (size >= 200)
		return (5);
	if (size >= 100)
		return (4);
	return (2);
}

int	get_value(t_stack *stack, int value)
{
	int			i;
	t_list	*tmp;

	tmp = stack->top;
	if (!tmp)
		return (-1);
	i = 0;
	while (tmp)
	{
		if (*((int *)tmp->content) == value)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

void	sort_big_rotate_stack_a(t_stack *a, int start)
{
	int	value;

	while (1)
	{
		value = get_value(a, start - 1);
		if (value == a->size - 1)
			break ;
		ra(a);
	}
}

void	sort_big_empty_stack_b(t_stack *a, t_stack *b, int start)
{
	int	value;
	int	min_index;
	int	max_index;

	while (b->size)
	{
		min_index = get_value(b, get_min_value(b));
		max_index = get_value(b, get_max_value(b));
		if (min_index <= max_index)
			value = min_index;
		else
			value = max_index;
		if (value == 0)
		{
			pa(a, b);
			if (min_index <= max_index)
				ra(a);
		}
		else if (value >= b->size / 2)
			rrb(b);
		else
			rb(b);
	}
	sort_big_rotate_stack_a(a, start);
}

void	sort_big_fill_stack_b(t_stack *a, t_stack *b, int start, int end)
{
	int	value;

	while (1)
	{
		value = get_first_range_value(a, start, end);
		if (value == -1)
			break ;
		if (value == 0)
			pb(a, b);
		else if (value > a->size / 2)
			rra(a);
		else
			ra(a);
	}
	while (start > 0)
	{
		value = get_value(a, start - 1);
		if (value == a->size - 1)
			break ;
		rra(a);
	}
}

int	get_first_range_value(t_stack *stack, int start, int end)
{
	int		i;
	t_list	*tmp;

	tmp = stack->top;
	if (!tmp)
		return (-1);
	i = 0;
	while (tmp)
	{
		if (*((int *)tmp->content) >= start && *((int *)tmp->content) <= end)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

void	sort_big(t_stack *a, t_stack *b)
{
	int		size;
	t_chunk	*chunk;

	init_chunk(chunk);
	size = a->size;
	chunk.pieces = compute_chunk_pieces(size);
	chunk.size = size / chunk.pieces;
	chunk.start = 0;
	chunk.end = chunk.size;
	while (chunk.pieces--)
	{
		sort_big_fill_stack_b(a, b, chunk.start, chunk.end - 1);
		chunk.start = chunk.end;
		if (chunk.pieces == 1)
			chunk.end = size;
		else
			chunk.end += chunk.size;
		sort_big_empty_stack_b(a, b, chunk.start);
	}
}