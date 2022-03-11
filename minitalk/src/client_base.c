/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:58:50 by lgenevey          #+#    #+#             */
/*   Updated: 2022/03/11 16:38:54 by lgenevey         ###   ########.fr       */
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

/*
	send SIGUSR1 if bitwise result is 1. SIGUSR2 if 0.
	pid : on which process to send signals
	*s : text to compare to bits-bitwise
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
			{
				kill(pid, SIGUSR1);
				ft_printf("1");
			}
			else
			{
				kill(pid, SIGUSR2);
				ft_printf("0");
			}
			usleep(100200);
			bits++;
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
	pid_t 	pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Invalid arguments : [./client] [server's pid] [string]\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (!pid || pid < 0)
		return (0);
	message = argv[2];
	send_signals(pid, message);
	return (0);
}