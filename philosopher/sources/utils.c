/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:57:20 by nakawashi         #+#    #+#             */
/*   Updated: 2022/08/27 21:05:10 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	is_digit(int n)
{
	if (n >= '0' && n <= '9')
		return (1);
	else
		return (0);
}

/*
	return 0 if arguments :
	- are not numbers
	- are equal to 0
	- are lower than 5 or greater than 6
*/
int	are_args_valid(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!is_digit(argv[i][j]) || ft_atoi(argv[i]) == 0)
			{
				printf("Unvalid arguments !\n");
				return (0);
			}
			++j;
		}
		++i;
	}
	if (argc > 6)
		printf("Too many arguments !\n");
	else if (argc < 5)
		printf("Too few arguments !\n");
	else
		return (1);
	return (0);
}
