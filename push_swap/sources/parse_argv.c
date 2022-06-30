/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:03:13 by nakawashi         #+#    #+#             */
/*   Updated: 2022/07/01 01:54:26 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	solution pour pouvoir free la de figure sans ""
*/
static char	**copy_argv(int argc, char **argv)
{
	char	**cpy;
	int		i;

	cpy = malloc(sizeof(char *) * argc);
	i = 0;
	while (argv[i])
	{
		cpy[i] = ft_strdup(argv[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

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
		values = copy_argv(argc, argv);
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
			if (array[i][j] == '+' || array[i][j] == '-')
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
	Je malloc les deux cas de figure : avec et sans ""
	Récupère le nombre de valeurs à trier
	Je copie chaque string sur une nouvelle adresse (l125)
	Les convertis les string en integer
	Initialise ma chaine, ajoute à chaque élément le contenu.
*/
void	get_data(int argc, char **argv , t_stack *a, t_template *template)
{
	char	**str;
	char	*current;
	int		i;

	str = get_user_data(argc, argv);
	a->size = ft_count_arrays(str);
	current = NULL;
	if (a->size == 1)
		free_ppointer_and_exit(str);
	is_number(str);
	find_duplicate(str);
	i = 0;
	while (str[i])
	{
		current = str[i];
		template->int_array = (int *)malloc(sizeof(int));
		if (!template->int_array)
			free_ppointer_num_and_exit(str, template->int_array);
		*template->int_array = ft_atoi_check_overflow(current);
		printf("template->int_array : %d\n", template->int_array[i]);
		ft_lstadd_back(&a->top, ft_lstnew(template->int_array));
		++i;
	}
	ft_free_ppointer(str);
}
