/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:30:59 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/11 16:06:58 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *philo)
{
	t_philo *p;

	p = (t_philo *) philo;
	int i = 0;
	while (i < 100)
	{
		p->fork_in_hands++;
		++i;
	}
	// doit pas aller à plus que deux
	printf("afficher nombre de fourchettes en main (pas plus que 2) : %d\n", p->fork_in_hands++);
}
