/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:27:23 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/11 17:34:32 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	initialize variables from t_args structure
*/
void	init_args(int argc, char **argv, t_args *args)
{
	args->nb_of_philos = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->number_of_times_each_philosopher_must_eat = -1;
	if (argc == 6)
		args->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
}

/*
	creates n arrays of t_philo structures (n = nb of philos)
	creates one thread per philosophe (pthread_create()
	returns the pointer to those structures
*/
t_philo	*create_philos(t_args *args, t_rules *rules)
{
	int	i;

	rules->philos_array = malloc(args->nb_of_philos * sizeof(t_philo));
	if (!rules->philos_array)
		return (NULL);
	i = 1;
	while (i <= args->nb_of_philos)
	{
		rules->philos_array[i].id = i;
		rules->philos_array[i].meal_eaten = 0;
		if (pthread_create(&rules->philos_array->thread, NULL, routine, &rules->philos_array[i]) != 0)
			return (ERR_THREAD_CREATION);
		printf("%u %u is thinking\n", rules->timestamp_in_ms, rules->philos_array[i].id);
		++i;
	}
	return (rules->philos_array);
}

