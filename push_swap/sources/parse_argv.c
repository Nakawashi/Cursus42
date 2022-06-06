/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:03:13 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/06 18:57:17 by nakawashi        ###   ########.fr       */
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



char	*parse_arguments(int argc, char **argv)
{
	char	**values;
	char	*array;
	int		nb_of_args;
	int		i;
	int		j;

	nb_of_args = argc--; //dont want to count prg name
	values = argv++;
	array = NULL;
	if (nb_of_args == 2)
		values = ft_split(argv[0], ' ');
	else
		values = argv; // start after prg name
	i = 0;
	while (values[i])
	{
		j = 0;
		while (values[i][j])
		{
			ft_printf("values[i][j] : %s\n", values[i][j]);
			array[j] = values[i][j];
			j++;
		}
		i++;
	}
	ft_printf("array : %s\n", array);
	return (array);
}

/*

	if (!is_integer(values))
		clean();
	if (!is_duplicated(values))
		clean();

*/
