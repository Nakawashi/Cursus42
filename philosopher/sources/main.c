/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:31:39 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/18 22:53:54 by nakawashi        ###   ########.fr       */
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
	if (errno)
		return (1);
	init_args(argc, argv, &rules);
	if (init_rules(&rules) || start_simulation(&rules))
	{
		free(&rules.philos_array);
		free(&rules.fork_array);
		return (1);
	}
	free(&rules.philos_array);
	free(&rules.fork_array);
	return (0);
}
