/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 00:44:13 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/19 13:18:34 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	Dans le cas ou on a mis l'argument nb of times they must eat
	Retourne 1 si le compte est bon
*/
static int	check_eat(t_rules *rules)
{
	int	i;

	if (rules->args.nb_of_times_they_must_eat == 0)
		return (0);
	i = 0;
	while (i < rules->args.nb_philos)
	{
		if (rules->philos_array[i].eat_count
			< rules->args.nb_of_times_they_must_eat)
			return (0);
		++i;
	}
	rules->all_meals_eaten = 1;
	return (1);
}

/*
	temps de dormir, on attend tant que tout le monde est vivant
	tous n'ont pas encore mangé
	qu'on dépasse pas le temps donné en argument argv[4]
*/
static void	philo_slept(t_philo *philo, long long time)
{
	long long	tstart;

	tstart = get_time_in_ms();
	while (philo->rules->all_alive && philo->rules->all_meals_eaten == 0
		&& get_time_in_ms() - tstart < time)
		usleep(50);
}

/*
	print un message de log selon l'état, au moment ou la fonction est appelée
	mais que si tout le monde est encore vivant et le nb de repas donnés
*/
static void	print_log(t_philo *philo, char *s)
{
	long long	time;

	time = get_time_in_ms() - philo->rules->start_time;
	pthread_mutex_lock(&philo->rules->msg_log);
	if (philo->rules->all_alive && philo->rules->all_meals_eaten == 0)
		printf("%lld ms %u %s\n", time, philo->id, s);
	pthread_mutex_unlock(&philo->rules->msg_log);
}

/*
	l74 : si 1 seul philo il prend pas de 2nd fourchette
*/
static void	philo_eats(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_log(philo, "has taken a fork left");
	if (philo->rules->args.nb_philos > 1)
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
	l100, 101 : évite au max les deadlocks
*/
void	*routine(void *philo)
{
	t_philo	*a_philo;

	a_philo = (t_philo *) philo;
	a_philo->last_meal = get_time_in_ms();
	if (a_philo->id % 2)
		usleep(500);
	while (a_philo->rules->all_alive && !a_philo->rules->all_meals_eaten)
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
