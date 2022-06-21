/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:43:58 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/21 15:12:26 by lgenevey         ###   ########.fr       */
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
		num = check_datas(argc, argv);
		if(!fill_stack(num, &a))
		{
			ft_lstclear(&(a.top), free);
			free(num);
			return (0);
		}
		init_stack(&b);
		push_swap(&a, &b);
		while (a.top)
		{
			printf("liste dans l'ordre : [%d]\n", *((int *)a.top->content));
			a.top = a.top->next;
		}
	}
	return (0);
}
