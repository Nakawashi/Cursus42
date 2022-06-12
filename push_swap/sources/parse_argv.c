/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:03:13 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/12 20:58:21 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(char **array)
{
	int		i;
	int		j;
	char	current;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			current = array[i][j];
			if (current == array[i][j + 1])
				print_error_and_exit();
			j++;
		}
		i++;
	}
	return (1);
}

/*
	parcours chaque caractère du tableau pour definir si ce sont bien des digit
	tiens compte des nombres negatifs
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
		while (array[i][j])
		{
			if (array[i][j] == '+'|| array[i][j] == '-')
				j++;
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

	values = ++argv;
	if (argc == 2)
		values = ft_split(argv[0], ' ');
	else
		values = argv;
	return (values);
}
