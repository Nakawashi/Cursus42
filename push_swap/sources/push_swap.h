/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:15:01 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/28 13:05:45 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libraries/libft/libft.h"
# include "../libraries/libft/ft_printf/ft_printf.h"

# define ERR_ARG "Error : ./push_swap \"numbers\" or ./push_swap [int] [int]
# define ERR_NOT_INTEGERS "Error : Some arguments are not integers"
# define ERR_DUPPLICATES "Error : Some arguments are dupplcated"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

// cell, element of the list
typedef struct s_book
{
	int				data;
	struct s_book	*prev;
	struct s_book	*next;
}	t_book;

// where the list starts (une pile de livre - umerat)
typedef struct s_stack
{
	int		size;
	t_book	*first;
	t_book	*last;
}	t_stack;

int	parse_arguments(int argc, char **argv);

#endif
