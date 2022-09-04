/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:06:14 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/04 18:25:59 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

enum e_errors
{
	NB_ARGUMENTS = 0,
	INVALID_VALUE = 1
};

enum e_philo_state
{
	THINKING = 0,
	EATING = 1,
	SLEEPING = 2,
	DEAD = 3,
};

typedef struct s_args
{
	int	nb_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_args;

typedef struct s_philo
{
	unsigned		id;
	int				fork_in_hands;
	unsigned int	state;
	unsigned int	meal_eaten;

}	t_philo;

typedef struct s_fork
{
	int	id;
	int	state;
}	t_fork;

typedef struct s_global
{
	t_args			*args;
	t_philo			*philos;
	t_fork			*forks;
	unsigned int	prog_start;
	unsigned int	timestamp_in_ms;
	pthread_mutex_t	mutex1;
	pthread_mutex_t	mutex2;
}	t_global;

// mini_libft.c : because entire libft is not allowed

int		ft_atoi(const char *str);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr(int n);

// init.c : init structures' variables
void	init_args(int argc, char **argv, t_args *args);
t_philo	*create_philos(t_args *args, t_global *global);
t_fork	*create_forks(t_args *args);

// utils.c : fonctions utiles propre à ce projet
int		error(int type_of_error);
int		is_even(int n);
int		are_args_valid(int argc, char **argv);
void	get_time_in_ms(struct timeval *tp, t_global *global);

#endif
