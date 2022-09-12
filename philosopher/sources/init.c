/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:27:23 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/13 01:14:06 by nakawashi        ###   ########.fr       */
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
	args->nb_of_times_each_philo_must_eat = -1;
	if (argc == 6)
		args->nb_of_times_each_philo_must_eat = ft_atoi(argv[5]);
}

/*
	creates n arrays of t_philo structures (n = nb of philos)
	creates one thread per philosophe (pthread_create()
	returns the pointer to those structures
*/
static int	init_philos(t_args *args, t_rules *rules)
{
	int	i;

	i = 1;
	while (i <= args->nb_of_philos)
	{
		rules->philos_array[i].id = i;
		rules->philos_array[i].eat_count = 0;
		rules->philos_array[i].last_meal = get_time_in_ms();
		rules->philos_array[i].left_fork = &rules->fork_array[i];
		rules->philos_array[i].right_fork = &rules->fork_array[(i + 1) % args->nb_of_philos];
		rules->philos_array[i].rules = rules;
		if (pthread_mutex_init(&rules->fork_array[i], NULL) != 0)
			return (error(ERR_MUTEX_INIT));
		++i;
	}
	return (0);
}

int	init_rules(t_rules *rules, t_args *args)
{
	rules->philos_array = NULL;
	rules->fork_array = NULL;
	rules->all_alive = 1;
	rules->all_eat = 0;
	rules->philos_array = malloc(sizeof(t_philo) * args->nb_of_philos);
	rules->fork_array = malloc(sizeof(pthread_mutex_t) * args->nb_of_philos);
	if (!rules->philos_array || !rules->fork_array)
		return (error(ERR_MALLOC));
	if (pthread_mutex_init(&rules->msg_log, NULL) != 0)
		return (error(ERR_MUTEX_INIT));
	return (init_philos(args, rules));
}

