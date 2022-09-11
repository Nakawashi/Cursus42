/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:31:39 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/11 17:34:03 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_args 			args;
	t_rules			rules;

	if (argc < 5 || argc > 6)
		return (error(ERR_NB_ARGUMENTS));
	if (!are_args_valid(argc, argv))
		return (error(ERR_INVALID_VALUE));
	init_args(argc, argv, &args);
	rules.philos_array = create_philos(&args, &rules);
}
