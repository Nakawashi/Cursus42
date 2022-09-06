/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:06:14 by nakawashi         #+#    #+#             */
/*   Updated: 2022/09/06 19:07:32 by lgenevey         ###   ########.fr       */
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
	NB_ARGUMENTS = 0,
	INVALID_VALUE = 1
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

typedef struct s_rules
{
	t_args			*args;
	t_philo			*philos;
	t_mutex			*fork;
	t_mutex			writing;
	unsigned int	prog_start;
	unsigned int	timestamp_in_ms;
}	t_rules;

typedef struct s_philo
{
	unsigned		id;
	int				fork_in_hands;
	unsigned int	state;
	unsigned int	meal_eaten;
	unsigned int	last_meal;
	pthread_mutex_t	fork_left;
	pthread_mutex_t	fork_right;
}	t_philo;

// mini_libft.c : because entire libft is not allowed

int		ft_atoi(const char *str);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr(int n);

// init.c : init structures' variables
void	init_args(int argc, char **argv, t_args *args);
t_philo	*create_philos(t_args *args, t_rules *global);

// utils.c : fonctions utiles propre à ce projet
int		error(int type_of_error);
int		is_even(int n);
int		are_args_valid(int argc, char **argv);
void	get_time_in_ms(struct timeval *tp, t_rules *global);

#endif
