/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:43:58 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/30 18:43:22 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_template	template;
	int			*num;

	if (argc > 1)
	{
		init_stack(&a);
		num = check_datas(argc, argv, &a);
		if (!fill_stack(num, &a))
		{
			free(num);
			ft_lstclear(&(a.top), free);
			return (0);
		}
		init_stack(&b);
		init_template(&template, a.size, num);
		free(num);
		push_swap(&a, &b, &template);
		if (TEST)
			print_stack(&a, &b);
	}
	return (0);
}
