/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:06:14 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/13 00:00:06 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo	t_philo;

enum e_errors
{
	ERR_NB_ARGUMENTS = 1,
	ERR_INVALID_VALUE,
	ERR_THREAD_CREATION,
	ERR_MUTEX_INIT,
	ERR_MALLOC,
};

enum e_philo_state
{
	THINKING = 1,
	EATING,
	SLEEPING,
	DEAD
};

typedef struct s_args
{
	int	nb_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat; // nb eat
}	t_args;

typedef struct s_rules
{
	int				all_alive;
	int				all_eat;
	long long		timestamp_in_ms; // t0
	t_philo			*philos_array;
	pthread_mutex_t	*fork_array;
	pthread_mutex_t	msg_log;
}	t_rules;

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	eat_count;
	long long		last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_rules			*rules;
}	t_philo;

// mini_libft.c : because entire libft is not allowed
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr(int n);

// init.c : init structures' variables
void	init_args(int argc, char **argv, t_args *args);
int		init_rules(t_rules *rules, t_args *args);


// utils.c : fonctions utiles propre à ce projet
int			error(int type_of_error);
int			is_even(int n);
int			are_args_valid(int argc, char **argv);
long long	get_time_in_ms(void);
void		*routine(void *philo);

#endif
