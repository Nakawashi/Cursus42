/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:27:23 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/05 22:38:58 by nakawashi        ###   ########.fr       */
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
t_fork	*create_forks(t_args *args)
{
	t_fork		*forks;
	int			i;
	//pthread_t	thread_id;

	forks = malloc(args->nb_of_philos * sizeof(t_fork));
	if (!forks)
		return (NULL);
	i = 1;
	while (i <= args->nb_of_philos)
	{
		//pthread_create(&thread_id, NULL, )
		forks[i].id = i;
		forks[i].state = 0;
	}
	return (forks);
}

