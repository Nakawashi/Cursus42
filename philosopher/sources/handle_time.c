/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:56:50 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/04 16:58:50 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	Returns the timestamp in milliseconds
*/
void	get_time_in_ms(t_global *global)
{
	struct timeval tp;

	gettimeofday(&tp, NULL);
	global->prog_start = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	//gettimeofday(&tp, NULL);
	global->timestamp_in_ms = (tp.tv_sec * 1000 + tp.tv_usec / 1000) - global->prog_start;
}
