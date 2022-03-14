/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:58:50 by lgenevey          #+#    #+#             */
/*   Updated: 2022/03/14 17:05:39 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	ft_atoi(const char *str)
{
	int		i;
	long	v;
	int		sign;

	i = 0;
	v = 0;
	sign = 1;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		v += str[i] - 48;
		v *= 10;
		i++;
	}
	return ((v * sign) / 10);
}

// pause() : se remet en route si un signal est emis

/*
	-- description
	tells what to do when client get SIGUSR1 from server (= inform the user
	that the message is over and well sent)
*/
void	sigusr_handler(int signal, siginfo_t *siginfo, void *unused)
{
	(void) siginfo;
	(void) *unused;
	if (signal == SIGUSR1)
		ft_printf("message recu! %d\n", siginfo->si_pid);
}


/*
	- description
	send SIGUSR1 if bitwise comparaison result is 1. SIGUSR2 if 0.

	- arguments
	pid : on which process to send signals
	*s : we gonna check each bits from each char to send USR1 or USR2

	- code explanation
	pause() : lock the process until a new signal arrives. Ready to get
	the kill() from the server (acknowledgement)
*/
static void	send_signals(pid_t pid, char *s)
{
	int	bits;
	int	i;

	i = 0;
	while (s[i])
	{
		bits = 0;
		while (bits <= 7)
		{
			if (s[i] & (1 << bits))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bits++;
			pause();
		}
		i++;
	}
}

/*
	here I use signal to send USR1 and USR2 depending on bitwise result
	I check server side the function of each signal.
*/
int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;
	struct	sigaction bernardo;

	if (argc != 3)
	{
		ft_printf("Invalid arguments : [./client] [server's pid] [string]\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (!pid || pid < 0)
		return (0);
	message = argv[2];
	sigemptyset(&bernardo.sa_mask);
	bernardo.sa_sigaction = &sigusr_handler;
	bernardo.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &bernardo, NULL);
	send_signals(pid, message);
	return (0);
}