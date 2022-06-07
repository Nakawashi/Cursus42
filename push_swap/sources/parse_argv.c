/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:03:13 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/07 15:07:11 by nakawashi        ###   ########.fr       */
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
	while (array[i])
	{
		j = 0;
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
	values : argv that we split then duplicated with malloc (ft_strdup)
*/
char	**get_user_data(int argc, char **argv)
{
	char	**values;
	int		nb_of_args;

	nb_of_args = argc--;
	values = argv++;
	if (nb_of_args == 2)
		values = ft_split(argv[0], ' ');
	else
		values = argv;
	return (values);
}

