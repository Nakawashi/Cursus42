/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:43:58 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/28 13:16:33 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char **test;

	test = argv;

	t_book *list = emptyList();

	list = freeList(list);

	if (argc > 1)
		parse_arguments(argc, **argv);
	return (0);
}
