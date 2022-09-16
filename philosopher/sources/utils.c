/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:57:20 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/16 13:23:14 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	free_ppointers(t_rules *rules)
{
	if (rules->philos_array)
		free(rules->philos_array);
	if (rules->fork_array)
		free(rules->fork_array);
}

int	error(t_rules *rules, int type_of_error)
{
	if (type_of_error == ERR_NB_ARGUMENTS)
	{
		printf("Error : must get 5 or 6 arguments\n");
		printf(" [1] nb of philos\n [2] time to die\n [3] time to eat\n"
		" [4] time to sleep\n [5] [nb_of_times_each_philo_must_eat]\n");
	}
	else if (type_of_error == ERR_INVALID_VALUE)
		printf("Error : values must be an integer and not equal to 0\n");
	else if (type_of_error == ERR_THREAD_CREATION)
		printf("Error while creating a thread\n");
	else if (type_of_error == ERR_MUTEX_INIT)
		printf("Error while initializing a mutex\n");
	else if (type_of_error == ERR_MALLOC)
		printf("Error while allocating memory for array of philos or forks\n");
	else if (type_of_error == ERR_JOIN_THREAD)
		printf("Error while joining thread\n");
	else if (type_of_error == ERR_MUTEX_DESTROY)
		printf("Error while destoy mutex\n");
	free_ppointers(rules);
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
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

/*
	Retourne la différence de temps entre "maintenant" et prog_start
*/
long long	get_time_in_ms(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return (tp.tv_sec * 1000 +tp.tv_usec / 1000);
}
