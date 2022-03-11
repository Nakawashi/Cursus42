/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:59:03 by lgenevey          #+#    #+#             */
/*   Updated: 2022/03/11 15:29:25 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/*
	rebuild the letter
	position : in which bit we are between the 8th (position++ means we move one
	to the leftv)
	letter : 8 bits to make a letter
	letter |= (1 << position) :  compare the char to 1 then move to left
*/
static void	sigusr_handler(int signal)
{
	static char 	letter;
	static int		position;

	letter = 0;
	position = 0;
	if (signal == SIGUSR1)
		letter |= (1 << position);
	position++;
	if (position == 7)
	{
		ft_printf("%c", letter);
		position = 0;
		letter = 0;
	}
}


/*
	usage of sigaction : to associate a signal to a handler
*/
int	main(void)
{
	struct sigaction bernard;

	bernard.sa_sigaction = &sigusr_handler;
	sigemptyset(&bernard.sa_mask);
	sigaddset(&bernard.sa_mask, SIGUSR1);
	sigaddset(&bernard.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &bernard, NULL);
	sigaction(SIGUSR2, &bernard, NULL);
	ft_printf("Server's PID : %d\n", getpid());
	return (0);
}