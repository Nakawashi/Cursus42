/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:03:13 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/01 16:00:40 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	get user datas and return them in a pointer of array of [int]
	ft_split if only 2 arguments
*/
static int	*get_data(int argc, char **argv)
{
	char	**char_array;
	int		*int_array;
	int		i;
	int		j;

	char_array = NULL;
	int_array = 0;
	if (argc == 2)
		char_array = ft_split(argv[1], ' '); // tableau qui recupere les entrees du second argument
	else
		char_array = ++argv; // tableau qui recupere les entrees on pousse ici pour partir du second argument, on veut pas le nom du programme
	i = 0;
	while (char_array[i])
		{
			ft_printf("char_array[i] : [%s]\n", char_array[i]);
			i++;
		}
	write(1, "\n", 1);
	i = 0;
	while (char_array[i]) // convertir les char en int pour creer le tableau de int
	{
		j = 0;
		while (char_array[i][j])
		{
			int_array[i] = ft_atoi(char_array[i]);
			if (int_array[i] > INT_MAX || int_array[i] < INT_MIN)
				ft_printf("int overflow");
			j++;
		}
		i++;
	}
	return (int_array);
}

static int	*check_int(int  *data_to_check)
{
	int	i;

	i = 0;
	while (data_to_check[i])
	{
		i++;
	}
	return (data_to_check);
}

// static int	check_duplicates(char **data_to_check)
// {
// 	return (0);
// }

/*
	User arguments must be int and not duplicated numbers.
*/
int	parse_arguments(int argc, char **argv)
{
	int	*values;

	values = get_data(argc, argv);
	check_int(values);
	// check_duplicates(values);
	return (1);
}
