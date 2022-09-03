/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:31:39 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/03 13:15:53 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// prints time, sleeps 200ms, repeat
int	main(int argc, char **argv)
{
	t_args args;

	if (argc < 5 || argc > 6)
		return (error(NB_ARGUMENTS));
	if (!are_args_valid(argc, argv))
		return (error(INVALID_VALUE));
	init_args(argc, argv, &args);
	printf("nb philo : %d\n", args.number_of_philosophers);
	printf("die : %d\n", args.time_to_die);
	printf("eat : %d\n", args.time_to_eat);
	printf("sleep : %d\n", args.time_to_sleep);



/* 	printf("argv 1 : %d\n", ft_atoi(argv[1]));
	printf("number of philosophers : %d\n", args.number_of_philosophers);

	printf("argv 2 : %d\n", ft_atoi(argv[2]));
	printf("time to die : %d\n", args.time_to_die);

	printf("argv 3 : %d\n", ft_atoi(argv[3]));
	printf("time to eat : %d\n", args.time_to_eat);

	printf("argv 4 : %d\n", ft_atoi(argv[4]));
	printf("time to sleep : %d\n", args.time_to_sleep);

	printf("argc : %d\n", argc);
	printf("nb of time each philos must eat : %d\n", args.number_of_times_each_philosopher_must_eat);
 */

	unsigned int	prog_start;

	prog_start = get_time();
	printf("start time value : %u", prog_start);
	/* while (1)
	{
		printf("%ld\n", get_time() - prog_start);
		usleep(200 * 1000);
	} */


	return (0);
}
