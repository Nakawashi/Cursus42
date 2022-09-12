/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:31:39 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/12 23:55:35 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_args 			args;
	t_rules			rules;

	if (argc < 5 || argc > 6)
		return (error(ERR_NB_ARGUMENTS));
	if (are_args_valid(argc, argv) != 0)
		return (error(ERR_INVALID_VALUE));
	init_args(argc, argv, &args);
	init_rules(&rules, &args);


	printf("\nCheck init args, philos and rules structures : \n");
	printf("args.nb_of_philos :	%d\n", args.nb_of_philos);
	printf("args.time_to_die :	%d\n", args.time_to_die);
	printf("args.time_to_eat :	%d\n", args.time_to_eat);
	printf("args.time_to_sleep :	%d\n", args.time_to_sleep);
	if (argc == 6)
		printf("args.number_of_times_each_philosopher_must_eat : %d\n\n", args.number_of_times_each_philosopher_must_eat);
	//printf("rules.philos_array[0].id :	%d\n", rules.philos_array[0].id);
	printf("rules.all_alive :	%d\n", rules.all_alive);
	printf("rules.timestamp_in_ms :	%lld\n", rules.timestamp_in_ms);


	return (0);
}
