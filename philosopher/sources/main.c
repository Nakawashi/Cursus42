/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:31:39 by nakawashi         #+#    #+#             */
/*   Updated: 2022/08/22 16:53:09 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
