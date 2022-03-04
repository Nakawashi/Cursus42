/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:59:03 by lgenevey          #+#    #+#             */
/*   Updated: 2022/03/04 14:59:26 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	get information
	display it
	send acknowlwdge to client
	---
	Manual says to use sigaction() instead of signal() for portability reasons

*/

#include "../includes/minitalk.h"




/*
	Here we create signal handler
	int sig : signal that needs to be handled
*/
void	sig_handler(int sig)
{
	if (sig == SIGUSR1 || sig == SIGUSR2)
		ft_printf("blblblbl");
}

/*
	error checker
*/
int	main(void)
{
	ft_putnbr(getpid()); // get and write pid we can use it on client
	while(1)
	{
		pause();
	}

	return (0);
}

/*
recuperer le bordel
envoyer un signal avec que des 0 qui indiquera au client que cest bon

*/