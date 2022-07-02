/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:03:13 by nakawashi         #+#    #+#             */
/*   Updated: 2022/07/02 19:36:29 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		values = ft_strdup_ppointer(argc, argv);
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
				print_error_freeppointer_and_exit(array);
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
				print_error_freeppointer_and_exit(array);
			j++;
		}
	}
}

/*
	/!\ à la copie d'adresse
	n : intermediaire entre le tableau template et la liste
	-> il recupere les valeurs du tableau template en reservant un nouvel
	emplacement memoire et remplit la liste chainee avec.
	La liste ne sera plus triee en meme temps que le tableau template
	Par contre la liste est liee a n
	template->int_array : me permet de choisir mes pivots
*/
static void	fill_stack(char **str, t_template *template, t_stack *a)
{
	char	*str_cpy;
	int		i;
	int		*n;

	i = 0;
	n = NULL;
	str_cpy = NULL;
	while (str[i])
	{
		str_cpy = str[i];
		template->int_array[i] = ft_atoi_check_overflow(str_cpy);
		n = malloc(sizeof(int *));
		if (n == NULL)
			exit(0);
		*n = template->int_array[i];
		ft_lstadd_back(&a->top, ft_lstnew(n));
		++i;
	}
}

/*
	Je malloc les deux cas de figure : avec et sans ""
	Récupère le nombre de valeurs à trier
	Je copie chaque string sur une nouvelle adresse (l125)
	Les convertis les string en integer
	Initialise ma chaine, ajoute à chaque élément le contenu.
*/
void	get_data(int argc, char **argv, t_stack *a, t_template *template)
{
	char	**str;

	str = get_user_data(argc, argv);
	a->size = ft_count_arrays(str);
	if (a->size == 1)
		free_ppointer_and_exit(str);
	is_number(str);
	find_duplicate(str);
	template->int_array = (int *)malloc(sizeof(int) * a->size);
	if (template->int_array == NULL)
		exit (0);
	fill_stack(str, template, a);
	ft_free_ppointer(str);
}
