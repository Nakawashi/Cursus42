/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:03:13 by nakawashi         #+#    #+#             */
/*   Updated: 2022/05/30 16:17:09 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_int(char  **argv)
{
	return (0);
}

static int	check_duplicates(char  **argv)
{
	return (0);
}

/*
	ckeck arguments entered by the user
	if 2 arguments : means that every numbers are in double quotes
		split them
	else just keep

*/
int	parse_arguments(int argc, char **argv)
{
	char	**values;
	int		i;

	values = NULL;
	if (argc == 2)
	{
		values = ft_split(argv, ' ');
		if (!values)
			return (0);
	}
	i = 0;
	while (values[i])
	{
		ft_printf("values : %s", values[i]);
		i++;
	}
	check_int(values);
	check_duplicates(values);
	return (0);
}
