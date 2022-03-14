/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:58:50 by lgenevey          #+#    #+#             */
/*   Updated: 2022/03/14 19:13:00 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

// c'est laid mais pour afficher 1x le message acknowledge et pas 1 par bit
static int	g_once;

/*
	-- description
	client send 0 and 1 to server
	server get the 0s and 1s and rebuild letters from it
	when message is over, server send SIGUSR1, in our way, described in
	sa_handler (named sigusr1_handler()).
*/
int	main(int argc, char **argv)
{
	pid_t				pid;
	char				*message;
	struct sigaction	bernardo;

	g_once = 1;
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
	bernardo.sa_sigaction = &sigusr1_handler;
	bernardo.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &bernardo, NULL);
	send_signals(pid, message);
	return (0);
}

/*
	-- description
	send SIGUSR1 if bitwise comparaison result is 1. SIGUSR2 if 0.
	inside the signals we have 8 bits corresponding to a letter

	-- arguments
	pid : on which process to send signals
	*s : we gonna check each bit from each char to send USR1 or USR2

	-- code explanation
	-pause() : se remet en route si un signal est emis-
	pause() : lock the process until a new signal arrives. Ready to get
	the kill() from the server (acknowledgement)
*/
void	send_signals(pid_t pid, char *s)
{
	int	bit;
	int	i;

	i = 0;
	while (s[i])
	{
		bit = 0;
		while (bit < 8)
		{
			if (s[i] & (1 << bit))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			pause();
		}
		i++;
	}
}

/*
	-- description
	tells what to do when client get SIGUSR1 from server (= inform the user
	that the message is over and well sent)
*/
void	sigusr1_handler(int signal, siginfo_t *siginfo, void *unused)
{
	(void) *unused;
	if (signal == SIGUSR1 && g_once == 1)
	{
		ft_printf("message has been sent from server %d\n", siginfo->si_pid);
		g_once = 0;
	}
}

/*
	-- description
	ascii to int : we got pid in a string but we want a number.
*/
int	ft_atoi(const char *str)
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
