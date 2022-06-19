/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:03:13 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/19 16:14:32 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* MAKE SURE WE GOT DIGITS, INTEGER RANGE AND NO DUPLICATES */

/*
	return a pointer of char *arrays with user data
*/
static char	**get_user_data(int argc, char **argv)
{
	char	**values;

	if (!argv)
		return (NULL);
	values = ++argv;
	if (argc == 2)
		values = ft_split(argv[0], ' ');
	else
		values = argv;
	return (values);
}

/*
	Writes Error if a char is not a digit
	Does nothing if user writes + or - before the number
	Returns an array of integers
*/
static void	is_number(char **array)
{
	int	i;
	int	j;

	i = 0;
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
		i++;
	}
}

/*
	Writes Error at first found duplicated string / number
*/
static void	find_duplicate(char **array)
{
	int		i;
	int		j;
	char	*value_to_check;

	i = 0;
	while (array[i])
	{
		value_to_check = array[i];
		i++;
		j = i;
		while (array[j])
		{
			if (!ft_strcmp(array[j], value_to_check))
				print_error_and_exit();
			j++;
		}
	}
}

/*
	returns int *array from my char **array
	writes Error if int overflow or not convertible
*/
static int	*char_to_int(char **array)
{
	int	*num;
	int	i;

	num = (int *)malloc(sizeof(int) * ft_count_arrays(array));
	if (!num)
		return (0);
	i = 0;
	while (array[i])
	{
		num[i] = ft_atoi_check_overflow(array[i]);
		i++;
	}
	return (num);
}

int	*check_datas(int argc, char **argv)
{
	char	**str;

	str = get_user_data(argc, argv);
	is_number(str);
	find_duplicate(str);
	return (char_to_int(str));
}
