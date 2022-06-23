/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:43:58 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/23 19:11:06 by lgenevey         ###   ########.fr       */
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
		if (!fill_stack(num, &a))
		{
			free(num);
			return (0);
		}
		init_stack(&b);
		push_swap(&a, &b);
		if (TEST)
			print_stack(&a, &b);
		free(num);
	}
	return (0);
}
