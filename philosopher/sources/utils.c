/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:57:20 by nakawashi         #+#    #+#             */
/*   Updated: 2022/08/29 12:01:40 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	error(int type_of_error)
{
	if (type_of_error == NB_ARGUMENTS)
	{
		printf("Error : must get 5 or 6 arguments\n");
		printf(" nb of philos\n time to die\n time to eat\n time to sleep\n");
		printf(" [number_of_times_each_philosopher_must_eat]");
	}
	else if (type_of_error == INVALID_VALUE)
		printf("Error : values must be an integer and not equal to 0");
	return (1);
}

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
			if (!is_digit(argv[i][j]) || ft_atoi(argv[i]) <= 0)
			{
				printf("argument : %d\n", ft_atoi(argv[i]));
				return (0);
			}
			++j;
		}
		++i;
	}
	return (1);
}
