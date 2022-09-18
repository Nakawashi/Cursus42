/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:30:59 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/18 15:26:01 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	Check each philosopher when was his last meal
	Lock the log print message
	current_philo contient l'adresse du premier tableau
*/
static void	death_comming(t_rules *rules)
{
	int		i;
	t_philo	*curr_philo;

	while (rules->all_alive)
	{
		i = -1;
		while (++i < rules->args.nb_philos)
		{
			curr_philo = &rules->philos_array[i]; // curr philo contient l'adresse du premier tableau
			if (get_time_in_ms() - curr_philo->last_meal > rules->args.time_to_die)
			{
				pthread_mutex_lock(&rules->msg_log);
				rules->all_alive = 0;
				if (rules->all_eat == 0)
					printf("%lld ms %d has died\n", get_time_in_ms() - rules->timestamp_in_ms, curr_philo->id);
				pthread_mutex_unlock(&rules->msg_log);
				return ;
			}
		}
		usleep(50);
	}
}

/*
	create thread for each philosopher
	check death
	join thread to wait the end of the routines
	destroy mutexes for fork array
	destroy mutex about log message

	these pthread functions must return 0 if no errors
*/
int	start_simulation(t_rules *rules)
{
	int		i;
	t_philo	*philo;


	philo = rules->philos_array;
	rules->timestamp_in_ms = get_time_in_ms();
	i = -1;
	while (++i < rules->args.nb_philos)
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]) != 0)
			return (error(ERR_THREAD_CREATION));
	death_comming(rules);
	i = -1;
	while (++i < rules->args.nb_philos)
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (error(ERR_JOIN_THREAD));
	i = -1;
	while (++i < rules->args.nb_philos)
		if (pthread_mutex_destroy(&rules->fork_array[i]) != 0)
			return (error(ERR_MUTEX_DESTROY));
	if (pthread_mutex_destroy(&rules->msg_log) != 0)
		return (error(ERR_MUTEX_DESTROY));
	return (0);
}
