/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 00:44:13 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/18 15:26:52 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_eat(t_rules *rules)
{
	int	i;

	if (rules->args.nb_of_times_they_must_eat == 0)
		return (0);
	i = 0;
	while (i < rules->args.nb_philos)
	{
		if (rules->philos_array[i].eat_count < rules->args.nb_of_times_they_must_eat)
			return (0);
		++i;
	}
	rules->all_eat = 1;
	return (1);
}

/*
	besoin de comprendre
	temps de dormir, on attend tant que tout le monde est vivant
	tous n'ont pas encore mangé
	qu'on dépasse pas le temps donné en argument argv[4]
*/
static void	philo_sleapt(t_philo *philo, long long time)
{
	long long tstart;

	tstart = get_time_in_ms();
	while (philo->rules->all_alive && philo->rules->all_eat == 0
		&& get_time_in_ms() - tstart < time)
		usleep(50);
}

/*
	print un message de log selon l'état, au moment ou la fonction est appelée
*/
static void	print_log(t_philo *philo, char *s)
{
	long long	time;

	time = get_time_in_ms() - philo->rules->timestamp_in_ms;
	pthread_mutex_lock(&philo->rules->msg_log);
	if (philo->rules->all_alive && philo->rules->all_eat == 0)
		printf("%lld ms %u %s\n", time, philo->id, s);
	pthread_mutex_unlock(&philo->rules->msg_log);
}

static void	philo_eats(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_log(philo, "has taken a fork left");
	if (philo->right_fork != philo->left_fork)
	{
		pthread_mutex_lock(philo->right_fork);
		print_log(philo, "has taken a fork right");
		philo->last_meal = get_time_in_ms();
		print_log(philo, "is eating");
		philo->eat_count += 1;
		philo_sleapt(philo, philo->rules->args.time_to_eat);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
		while (philo->rules->all_alive)
			usleep(50);
	pthread_mutex_unlock(philo->left_fork);
}

/*
	Défini un ordre de qui va manger, pas tous en même temps

*/
void	*routine(void *philo)
{
	t_philo	*a_philo;

	a_philo = (t_philo *) philo;
	a_philo->last_meal = get_time_in_ms();
	if (a_philo->id % 2)
		usleep(500);
	while (a_philo->rules->all_alive && !a_philo->rules->all_eat)
	{
		philo_eats(a_philo);
		if (check_eat(a_philo->rules))
			break ;
		print_log(a_philo, "is sleeping");
		philo_sleapt(a_philo, a_philo->rules->args.time_to_sleep);
		print_log(a_philo, "is thinking");
	}
	return (NULL);
}
