/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:43:58 by lgenevey          #+#    #+#             */
/*   Updated: 2022/07/02 15:19:55 by lgenevey         ###   ########.fr       */
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
		get_data(argc, argv, &a, &template);
		if (TEST)
			print_stack(&a, &b);
		init_stack(&b);
		push_swap(&a, &b, &template);
		if (TEST)
			print_stack(&a, &b);
		ft_lstclear(&(a.top), free);
	}
	return (0);
}
