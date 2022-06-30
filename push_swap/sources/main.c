/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:43:58 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/30 15:22:28 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_template	template;

	if (argc > 1)
	{
		init_stack(&a);
		template.int_array = check_datas(argc, argv, &a);
		if (!fill_stack(template.int_array, &a))
		{
			free(template.int_array);
			ft_lstclear(&(a.top), free);
			return (0);
		}
		init_stack(&b);
		init_template(&template, &a, template.int_array);
		push_swap(&a, &b, &template);
		if (TEST)
			print_stack(&a, &b);
	}
	return (0);
}
