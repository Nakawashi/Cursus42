/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:15:01 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/14 15:01:50 by lgenevey         ###   ########.fr       */
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
# define ERR_NOT_INTEGERS "Error : Some arguments are not integers"
# define ERR_NOT_INTEGERS "Error : Some arguments are not integers"
# define ERR_DUPPLICATES "Error : Some arguments are dupplcated"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
	int		size;
	t_list	*top;
}	t_stack;

char	**get_user_data(int argc, char **argv);
void	print_error_and_exit();
void	is_number(char **array);
void	find_duplicate(char **array);
int		ft_strlen_arrays(char **array);
int		ft_atoi_check_overflow(const char *array);
int		fill_stack(char **array, t_stack *stack);

// push first prend pointeur e lelement
// push last
// pop first retourne l'element
// pop last

#endif
