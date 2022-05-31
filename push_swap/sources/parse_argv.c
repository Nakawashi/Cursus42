/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:03:13 by nakawashi         #+#    #+#             */
/*   Updated: 2022/05/31 16:46:14 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	get user datas and return them in a pointer of array
	ft_split if only 2 arguments
*/
static char	**get_data(int argc, char **argv)
{
	char	**values;
	int		i;

	values = NULL;
	if (argc == 2)
	{
		values = ft_split(argv[1], ' '); // tableau qui recupere les entrees du second argument
		i = 0;
		while (values[i])
		{
			ft_printf("values splitted : [%s]\n", values[i]);
			i++;
		}
		write(1, "\n", 1);
	}
	else
		values = ++argv; // tableau qui recupere les entrees on pousse ici pour partir du second argument, on veut pas le nom du programme
	i = 0;
	while (values[i])
	{
		ft_printf("values : {%s}\n", values[i]);
		i++;
	}
	write(1, "\n", 1);
	return (values);
}

static int	check_int(char  **data_to_check)
{
	int	i;

	i = 0;
	while (data_to_check[i])
	{
		ft_printf("before check int : {%s}\n", data_to_check[i]);
		if (data_to_check[i] > INT_MIN && data_to_check[i] < INT_MAX)
		{
				
		}
		else
			ft_printf("Erreur : int overflow\n");
		i++;
	}

	return (0);
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
	char	**values;

	values = get_data(argc, argv);
	check_int(values);
	// check_duplicates(values);
	return (1);
}
