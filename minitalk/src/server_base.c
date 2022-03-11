/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:59:03 by lgenevey          #+#    #+#             */
/*   Updated: 2022/03/11 16:33:26 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/*
	rebuild the letter
	position : in which bit we are between the 8th (position++ means we move one
	to the leftv)
	letter : 8 bits to make a letter
	line 32 : write 1 only if comparaison OR = 1, then shift left
*/
void	sigusr_handler(int signal, siginfo_t *siginfo, void *unused)
{
	static char 	letter = 0;
	static int		position = 0;

	(void) *unused;
	(void) siginfo;
	if (signal == SIGUSR1)
	{
		letter |= (1 << position);
		ft_printf("1");
	}
	else
		ft_printf("0");
	position++;
	if (position == 8)
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

	sigemptyset(&bernard.sa_mask);
	bernard.sa_sigaction = &sigusr_handler;
	bernard.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &bernard, NULL);
	sigaction(SIGUSR2, &bernard, NULL);
	ft_printf("Server's PID : %d\n", getpid());
	while(1)
		pause();
	return (0);
}