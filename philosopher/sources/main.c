/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:31:39 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/17 16:12:47 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;
	int		errno;

	errno = 0;
	if (argc < 5 || argc > 6)
		errno = (error(ERR_NB_ARGUMENTS));
	if (check_args(argc, argv))
		errno = (error(ERR_INVALID_VALUE));
	if (errno == 0)
	{
		init_args(argc, argv, &rules);
		if (init_rules(&rules) || start_simulation(&rules))
		{
			ft_free_t_philo_array(&rules.philos_array);
			ft_free_mutex_array(&rules.fork_array);
			return (1);
		}
	}
/* 	printf("\nCheck init args, philos and rules structures : \n");
	printf("args.nb_philos :	%d\n", args.nb_philos);
	printf("args.time_to_die :	%d\n", args.time_to_die);
	printf("args.time_to_eat :	%d\n", args.time_to_eat);
	printf("args.time_to_sleep :	%d\n", args.time_to_sleep);
	if (argc == 6)
		printf("args.nb_of_times_they_must_eat : %d\n\n", args.nb_of_times_they_must_eat);
	//printf("rules.philos_array[0].id :	%d\n", rules.philos_array[0].id);
	printf("rules.all_alive :	%d\n", rules.all_alive);
	printf("rules.timestamp_in_ms :	%lld\n", rules.timestamp_in_ms); */

	return (0);
}
