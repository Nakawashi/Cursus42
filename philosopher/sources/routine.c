/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:30:59 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/11 17:34:19 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	Cette fonction reçoit une structure concernant un philosophe
	et effectue ses actions dont certaines sont verrouillées car ne doivent pas
	se mélanger entre plusieurs threads en même temps.
*/
void	*routine(void *philo)
{
	t_philo *p;

	p = (t_philo *)philo;

	printf("afficher tableau de struct philos : %u\n", p->id);
	// doit pas aller à plus que deux
	return (NULL);
}
