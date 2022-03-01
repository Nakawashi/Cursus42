/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:58:50 by lgenevey          #+#    #+#             */
/*   Updated: 2022/03/01 18:42:24 by lgenevey         ###   ########.fr       */
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

void	send_bits(char c)
{
	int	i;

	// i = 8;
	// while(i > 0)
	// {
	// 	if (c & (1 << i))
	// 		kill(pid, SIGUSR1);
	// 	else
	// 		kill(pid, SIGUSR2);
	// }
	i = 8; // faire un paquet de 8 bits stockes dans une variable malloc
	while (i > 0)
	{
		putchar((c & (1 << i)) ? '1' : '0');
		i--;
	}

}

//https://github.com/lavrenovamaria/42-minitalk/blob/main/src/client.c
void	bit_by_bit(int pid, int bit)
{
	int	counter;

	counter = 0;
	while (counter <= 7)
	{
		if ((bit >> counter) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_putstr_fd("Error signal\n", 1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_putstr_fd("Error signal\n", 1);
		}
		counter++;
		usleep(100);
	}
}


int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Incorrect number of arguments.\n");
		ft_printf("[./client] [server's pid] [string]\n");
		return (0);
	}
	pid_t 	pid;
	char	*message;

	pid = ft_atoi(argv[1]);
	message = argv[2];
	//struct	sigaction bernard;

	//bernard.sa_handler = &handle_sigusr1; // link our signal handler to signal
	//sigaction(SIGUSR1, &bernard, NULL);

	// envoyer le message en utilisant



	return (0);
}

/*

infos necessaires :

pid
message recu
decortiquer la chaine pour transformer les char en bit sur 1 octet chaque
et envoyer chaque bit 1 à 1 avec kill()




*/