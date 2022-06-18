/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:43:58 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/18 17:43:03 by nakawashi        ###   ########.fr       */
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
		int i = 0;
		while (num[i])
		{
			printf("num[%d] = %d\n", i, num[i]);
			i++;
		}
		if(!fill_stack(num, &a))
		{
			ft_lstclear(&(a.top), free);
			free(num);
			return (0);
		}
		i = 0;
		while (a.top->content)
		{
			printf("a.top->content = %d\n", *((int *)a.top->content));
			a.top->content = a.top->content->next;
		}
		init_stack(&b);
		push_swap(&a, &b);
	}
	return (0);
}
