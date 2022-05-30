/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:15:01 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/30 17:21:23 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libraries/libft/libft.h"
# include "../libraries/libft/ft_printf/ft_printf.h"

# define ERR_ARG "Error : ./push_swap \"numbers\" or ./push_swap [int] [int]"
# define ERR_NOT_INTEGERS "Error : Some arguments are not integers"
# define ERR_DUPPLICATES "Error : Some arguments are dupplcated"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

// cell, element of the list
typedef struct s_elem
{
	int				data;
	struct s_elem	*prev;
	struct s_elem	*next;
}	t_elem;

// where the list starts (une pile de livre - umerat)
typedef struct s_stack
{
	int		size;
	t_elem	*top;
	t_elem	*bottom;
}	t_stack;

int		parse_arguments(int argc, char **argv);
t_stack	*init_stack(void);
t_elem	*init_elem(void);

// push first prent pointeur e lelement
// push last
// pop first retourne l'element
// pop last


#endif
