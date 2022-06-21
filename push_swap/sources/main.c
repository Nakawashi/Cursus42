/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:43:58 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/21 21:34:47 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		*num;

	if (argc > 1)
	{
		init_stack(&a);
		num = check_datas(argc, argv, &a);
		if(!fill_stack(num, &a))
		{
			ft_lstclear(&(a.top), free);
			free(num);
			return (0);
		}
		init_stack(&b);
		push_swap(&a, &b);
		printf("taille de b :	[%d]\n", ft_lstsize(b.top));
		while (a.top)
		{
			printf("-- Liste A --\n");
			printf("liste dans l'ordre : [%d]\n", *((int *)a.top->content));
			a.top = a.top->next;
		}
		printf("\n");
		while (b.top)
		{
			printf("-- Liste B --\n");
			printf("liste dans l'ordre : [%d]\n", *((int *)b.top->content));
			a.top = a.top->next;
		}
		printf("\n");
		ft_lstclear(&(a.top), free);
		ft_lstclear(&(b.top), free);
	}
	return (0);
}
