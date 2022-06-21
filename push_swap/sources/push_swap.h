/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:15:01 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/21 10:15:10 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libraries/libft/libft.h"
# include "../libraries/libft/ft_printf/ft_printf.h"

# define ERR_ARG "Error : ./push_swap \"numbers\" or ./push_swap [int] [int]"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
	int		size;
	t_list	*top;
}	t_stack;

// parse user arguments : parse_argv
int		*check_datas(int argc, char **argv);

// utils
int		ft_count_arrays(char **array);
int		ft_count_indexes(int *num);
int		ft_atoi_check_overflow(const char *array);

// error and cleaning
void	print_error_and_exit();
void	ft_free_array(char **array);

// stack and list handlers
void	init_stack(t_stack *stack);
int		fill_stack(int *num, t_stack *stack);

// algos
void	push_swap(t_stack *a, t_stack *b);
int		is_sorted(t_stack *stack);
void	sort_2_elements(t_stack *a);
void	sort_3_elements(t_stack *a);
void	sort_5_elements(t_stack *a, t_stack *b);

// allowed operations
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *stack);
void	rra(t_stack *stack);
void	pa(t_stack *b, t_stack *a);
void	pb(t_stack *a, t_stack *b);

#endif
