/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:56:50 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/04 18:08:37 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	Retourne la différence de temps entre "maintenant" et prog_start
*/
void	get_time_in_ms(struct timeval *tp, t_global *global)
{
	gettimeofday(tp, NULL);
	global->timestamp_in_ms = (tp->tv_sec * 1000 + tp->tv_usec / 1000) - global->prog_start;
}
