/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:58:56 by lgenevey          #+#    #+#             */
/*   Updated: 2022/03/14 18:15:27 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "../ft_printf/ft_printf.h"

void	send_signals(pid_t pid, char *s);
void	sigusr1_handler(int signal, siginfo_t *siginfo, void *unused);
int		ft_atoi(const char *str);
void	ft_sig_handler(int signal, siginfo_t *siginfo, void *unused);

#endif