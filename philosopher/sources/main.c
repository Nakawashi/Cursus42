/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:31:39 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/18 23:43:21 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;
	int		errno;

	errno = 0;
	if (argc < 5 || argc > 6)
	{
		printf(" [1] nb of philos\n [2] time to die\n [3] time to eat\n"
			" [4] time to sleep\n [5] [nb_of_times_they_must_eat]\n");
		return (1);
	}
	if (check_args(argc, argv))
	{
		printf("Error : values must be an integer > 0 and not equal to 0\n");
		return (1);
	}
	init_args(argc, argv, &rules);
	if (init_rules(&rules) || start_simulation(&rules))
		return (1);
	return (0);
}
