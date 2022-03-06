/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:58:50 by lgenevey          #+#    #+#             */
/*   Updated: 2022/03/04 18:32:04 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <string.h>
#include <stdio.h>

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

void sig_handler

/*
	si la comparaison avec le bit vaut 1, envoyer sigusr1 mais il n'est pas encore défini (sig handler)
	bits :
*/
void	send_bits(pid_t pid, char *s)
{
	int	bits;
	int	i;

	bits = 7;
	i = 0;
	while (s[i])
	{
		while (bits > 0)
		{
			if (s[i] & (1 >> i))
				kill(pid, SIGUSR1); // il faut encore définir ce que vaut sigusr1 via le sigaction
			else if (!(s[i] & (1 << i))) // juste mettre else sans condition, pas besoin
				kill(pid, SIGUSR2);
			ft_printf("s[i] : %c\n", s[i]);
			ft_printf("USR1 %d\n", SIGUSR1);
			ft_printf("USR1 %d\n", SIGUSR2);
			bits--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Incorrect number of arguments : [./client] [server's pid] [string]\n");
		return (0);
	}
	pid_t 	pid;
	char	*message;
	//struct	sigaction bernard;

	pid = ft_atoi(argv[1]);
	message = argv[2];


	//bernard.sa_handler = &handle_sigusr1; // link our signal handler to signal
	//sigaction(SIGUSR1, &bernard, NULL);

	// envoyer le message
	send_bits(pid, message);



	return (0);
}

/*

infos necessaires :

pid
message recu
decortiquer la chaine pour transformer les char en bit sur 1 octet chaque
et envoyer chaque bit 1 à 1 avec kill()

sigemptyset


*/