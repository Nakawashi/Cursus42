/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:31:39 by nakawashi         #+#    #+#             */
/*   Updated: 2022/08/06 14:01:18 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	Returns the timestamp in milliseconds
*/
long	get_time(void)
{
	struct timeval tp;
	long	milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

// prints time, sleeps 200ms, repeat
int	main(void)
{
	long	start_time;

	start_time = get_time();
	while (1)
	{
		printf("%ld\n", get_time() - start_time);

		usleep(200 * 1000);
	}
	return (0);
}
