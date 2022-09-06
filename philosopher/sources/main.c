/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:31:39 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/06 19:05:02 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_args 			args;
	t_rules			rules;
	t_philo			*philos;
	struct timeval	tp;

	if (argc < 5 || argc > 6)
		return (error(NB_ARGUMENTS));
	if (!are_args_valid(argc, argv))
		return (error(INVALID_VALUE));
	init_args(argc, argv, &args);
	gettimeofday(&tp, NULL);
	rules.prog_start = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	get_time_in_ms(&tp, &rules);
	philos = create_philos(&args, &rules);
	rules.philos = philos;
/* 	if (args.nb_of_philos == 1)
		return (one_philo_routine(&rules));
	return (philos_routine(&rules)); */
}
