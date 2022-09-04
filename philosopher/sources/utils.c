/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:57:20 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/04 18:24:37 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	error(int type_of_error)
{
	if (type_of_error == NB_ARGUMENTS)
	{
		printf("Error : must get 5 or 6 arguments\n");
		printf(" nb of philos\n time to die\n time to eat\n time to sleep\n");
		printf(" [number_of_times_each_philosopher_must_eat]\n");
	}
	else if (type_of_error == INVALID_VALUE)
		printf("Error : values must be an integer and not equal to 0\n");
	return (1);
}

/*
	returns 1 if n is even
*/
int	is_even(int n)
{
	if (n % 2 == 0)
		return (1);
	return (0);
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
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

/*
	Retourne la différence de temps entre "maintenant" et prog_start
*/
void	get_time_in_ms(struct timeval *tp, t_global *global)
{
	gettimeofday(tp, NULL);
	global->timestamp_in_ms = (tp->tv_sec * 1000 + tp->tv_usec / 1000) - global->prog_start;
}
