/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:03:13 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/06 17:10:38 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	1. get user datas and return them in an array of pointers
		ft_split if only 2 arguments
	2. all integers
	3. no duplicated numbers

	display errors if not.
	returns **char string
*/

static int	is_integer(char **char)
{

}

void	**parse_arguments(int argc, char **argv)
{
	int	nb_of_args;
	char **values;

	nb_of_args = argc--; //dont want to count prg name
	values = argv++;
	if (nb_of_args == 2)
		values = ft_split(argv[0], ' ');
	else
		values = argv; // start after prg name
	if (!is_integer(values))
		clean();
	if (!are_duplicated(values))
		clean();
}
