/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:15:01 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/18 16:13:56 by nakawashi        ###   ########.fr       */
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

void	print_error_and_exit();
void	init_stack(t_stack *stack);
void	ft_free_array(char **array);
void	push_swap(t_stack *a, t_stack *b);
int		*check_datas(int argc, char **argv);
int		ft_count_arrays(char **array);
int		ft_count_indexes(int *num);
int		ft_atoi_check_overflow(const char *array);
int		fill_stack(int *num, t_stack *stack);
int		is_sorted(t_stack *stack);

// push first prend pointeur e lelement
// push last
// pop first retourne l'element
// pop last

#endif
