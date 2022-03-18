/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:59:03 by lgenevey          #+#    #+#             */
/*   Updated: 2022/03/18 17:17:46 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/*
	-- description
	usage of sigaction : to associate a signal to a handler
	sig structure is a way to tell what to do with signals, through
	the function above : sa_sigaction() (which i named ft_sig_handler)

	-
	struct sigaction {
     void     (*sa_handler)(int);
     void     (*sa_sigaction)(int, siginfo_t *, void *);
     sigset_t   sa_mask;
     int        sa_flags;
     void     (*sa_restorer)(void);
	 -

	-- code explanation
	except for the line dedicated to display the process ID, everything is made
	for sending the acknowledgement to the client.
	1. creation of sig, our instance of what is going to do
	2. clean *set (pending or blocked signals)
	3. link sig to sa_sigaction function to tell what to do
	4. sa_flags : Si SA_SIGINFO est spécifié dans sa_flags, alors sa_sigaction
       (au lieu de sa_handler) spécifie la fonction de traitement du signal
       pour le signe.
	5. use sigaction in our way

*/
int	main(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = &ft_sig_handler;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	ft_printf("Server's PID : %d\n", getpid());
	while (1)
		;
	return (0);
}

/*
	-- description
	rebuild the letter, in the correct order ^^
	get USR1 or USR2 from client, here we tell what is each signal :
	USR1 is 1 and USR2 is 0

	-- arguments
	position : in which bit we are between the 8 bits
	(position++ : we move from left to right)
	letter : current letter, 8 bits to make a letter

	-- code explanation
	we know that info is coming 8 by 8
	1. write 1 only if  the result of the 'OR' is equal to 1, then
	shift '<-- x position' to the left to check next bit
	2. siginfo->si_pid : contient le pid du process qui a emis le signal
	3. usleep(200) : petit temps que je laisse entre les signaux
	4. send signal to client to say the message has been sent

*/
void	ft_sig_handler(int signal, siginfo_t *siginfo, void *unused)
{
	static char	letter = 0;
	static int	position = 0;

	(void) *unused;
	if (signal == SIGUSR1)
		letter = letter | (1 << position);
	position++;
	if (position == 8)
	{
		if (letter == 0)
			kill(siginfo->si_pid, SIGUSR1);
		ft_printf("%c", letter);
		position = 0;
		letter = 0;
	}
}
