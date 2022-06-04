/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:03:13 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/04 17:17:39 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	check_duplicates(char **data_to_check)
// {
// 	return (0);
// }

/*
	1. get user datas and return them in an array of pointers
		ft_split if only 2 arguments
	2. all integers
	3. no duplicated numbers

	display errors if not.

	returns **char string
*/
void	**parse_arguments(int argc, char **argv)
{
	int	nb_of_args;
	char **values;

	nb_of_args = argc--; //dont want to count prg name
	values = argv++; // start after prg name
	if (nb_of_args == 2)
		values = ft_split(argv[0], ' ');
	else
	{
		//check_int(values);
		values = (char **)malloc(sizeof(char *) * nb_of_args + 1);
		if (!values)
			return (NULL);
		values = argv;
	}
	//ft_printf("argv : %s\n", argv[0]);
	//ft_printf("values : %s\n", values[3]);
	//check_duplicates(values);
	return (NULL);
}
/*
	sinon on stock argv mais a partir du pointeur 1 (0 etant le nom du prg)
	donc la on a un tableau de pointeurs quil faut checker
*/
