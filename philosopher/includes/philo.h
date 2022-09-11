/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:06:14 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/11 17:33:53 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef pthread_mutex_t	t_mutex;
typedef pthread_t		t_pthread;

enum e_errors
{
	ERR_NB_ARGUMENTS = 1,
	ERR_INVALID_VALUE,
	ERR_THREAD_CREATION,
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
	int	number_of_times_each_philosopher_must_eat;
}	t_args;

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	meal_eaten;
	long long		last_meal;
	pthread_t		thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
}	t_philo;

typedef struct s_rules
{
	long long		die_time;
	long long		eat_time;
	long long		sleep_time;
	long long		timestamp_in_ms;
	t_args			*args;
	t_philo			*philos_array;
	pthread_mutex_t	*fork;
	pthread_mutex_t	printed_text;
}	t_rules;

// mini_libft.c : because entire libft is not allowed
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr(int n);

// init.c : init structures' variables
void	init_args(int argc, char **argv, t_args *args);
t_philo	*create_philos(t_args *args, t_rules *rules);

// utils.c : fonctions utiles propre à ce projet
int			error(int type_of_error);
int			is_even(int n);
int			are_args_valid(int argc, char **argv);
long long	get_time_in_ms(void);
void		*routine(void *philo);

#endif
