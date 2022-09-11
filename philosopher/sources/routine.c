/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:30:59 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/11 14:05:30 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	routine(void)
{
	int mails = 0;
	int i = 0;
	while (i < 10000)
	{
		++mails;
		++i;
	}
	printf("mails : %d\n", mails);
}
