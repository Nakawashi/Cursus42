/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:03:13 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/07 20:55:19 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	parcours chaque caractère du tableau pour definir si ce sont bien des digit
*/
int	is_number(char **array)
{
	int	i;
	int	j;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
	{
		j = 0;
		if (array[i][j] == '+'|| array[i][j] == '-')
			j++;
		while (array[i][j])
		{
			if (!ft_isdigit(array[i][j]))
				print_error_and_exit();
			j++;
		}
		ft_atoi_check_overflow(array[i]);
		i++;
	}
	return (1);
}

/*
	return a pointer of char *arrays with user data
*/
char	**get_user_data(int argc, char **argv)
{
	char	**values;
	int		nb_of_args;

	nb_of_args = --argc; // créée une copie si on met après
	values = ++argv;
	if (nb_of_args == 2)
		values = ft_split(argv[0], ' ');
	else
		values = argv;
	return (values);
}

