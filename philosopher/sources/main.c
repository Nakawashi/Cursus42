/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:31:39 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/04 18:13:38 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	creates n arrays of t_philo structures (n = nb of philos)
	returns the pointer to those structures
*/
t_philo	*create_philos(t_args *args, t_global *global)
{
	t_philo *philos;
	int		i;

	philos = malloc(args->nb_of_philos * sizeof(t_philo));
	if (!philos)
		return (NULL);
	i = 1;
	while (i <= args->nb_of_philos)
	{
		philos[i].id = i;
		philos[i].fork_in_hands = 0;
		philos[i].meal_eaten = 0;
		philos[i].state = THINKING;
		printf("%u %u is thinking\n", global->timestamp_in_ms, philos[i].id);
		++i;
	}
	return (philos);
}

/*
	creates n array of t_forks structures
	returns the pointer to those structures
*/
t_fork *create_forks(t_args *args)
{
	t_fork	*forks;
	int		i;

	forks = malloc(args->nb_of_philos * sizeof(t_fork));
	if (!forks)
		return (NULL);
	i = 1;
	while (i <= args->nb_of_philos)
	{
		forks[i].id = i;
		forks[i].state = 0;
	}
	return (forks);
}

/*

*/
int	main(int argc, char **argv)
{
	t_args 			args;
	t_global		global;
	struct timeval	tp;

	if (argc < 5 || argc > 6)
		return (error(NB_ARGUMENTS));
	if (!are_args_valid(argc, argv))
		return (error(INVALID_VALUE));
	init_args(argc, argv, &args);
	gettimeofday(&tp, NULL);
	global.prog_start = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	get_time_in_ms(&tp, &global);
	create_philos(&args, &global);
	create_forks(&args);

/*
	printf("nb philo : %d\n", args.nb_of_philos);
	printf("die : %d\n", args.time_to_die);
	printf("eat : %d\n", args.time_to_eat);
	printf("sleep : %d\n", args.time_to_sleep); */

	/* while (1)
	{
		printf("%ld\n", get_time() - prog_start);
		usleep(200 * 1000);
	} */


	return (0);
}
