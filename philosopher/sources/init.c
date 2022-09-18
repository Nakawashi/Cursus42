/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:27:23 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/18 22:43:24 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	initialize variables from t_args structure
*/
void	init_args(int argc, char **argv, t_rules *rules)
{
	rules->args.nb_philos = ft_atoi(argv[1]);
	rules->args.time_to_die = (long long)ft_atoi(argv[2]);
	rules->args.time_to_eat = (long long)ft_atoi(argv[3]);
	rules->args.time_to_sleep = (long long) ft_atoi(argv[4]);
	rules->args.nb_of_times_they_must_eat = 0;
	if (argc == 6)
		rules->args.nb_of_times_they_must_eat = ft_atoi(argv[5]);
}

/*
	Initialise chaque variable du tableau de structures philos_array
	Initialise les mutex pour chaque fourchette : on met pas toutes
	les fourchettes dans un seul mutex pour éviter le deadlock (ils
	commencent tous à prendre une fourchettent en même temps et attendent
	un temps infini pour prendre la seconde)
	Mettre l'adresse d'une fourchette du tableau dans la "main gauche" du pholo
	Mettre l'adresse i + 1 % nb_philos dans la main droite
	Initialiser un mutex pour la fourchette i car "la sienne"
	Retourne 0 si tout s'est bien passé
*/
static int	init_philos(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i <= rules->args.nb_philos)
	{
		rules->philos_array[i].id = i + 1;
		rules->philos_array[i].eat_count = 0;
		rules->philos_array[i].last_meal = get_time_in_ms();
		rules->philos_array[i].left_fork = &rules->fork_array[i];
		rules->philos_array[i].right_fork =
			&rules->fork_array[(i + 1) % rules->args.nb_philos];
		rules->philos_array[i].rules = rules;
		if (pthread_mutex_init(&rules->fork_array[i], NULL))
			return (error(ERR_MUTEX_INIT));
	}
	return (0);
}

/*
	Malloc here two pointers, philos and fork arrays
*/
int	init_rules(t_rules *rules)
{
	rules->philos_array = NULL;
	rules->fork_array = NULL;
	//rules->all_alive = 1;
	rules->is_dead = 0;
	rules->all_meals_eaten = 0;
	rules->philos_array = malloc(sizeof(t_philo) * rules->args.nb_philos);
	rules->fork_array =
		malloc(sizeof(pthread_mutex_t) * rules->args.nb_philos);
	if (!rules->philos_array || !rules->fork_array)
		return (error(ERR_MALLOC));
	if (pthread_mutex_init(&rules->msg_log, NULL) != 0)
		return (error(ERR_MUTEX_INIT));
	return (init_philos(rules));
}
