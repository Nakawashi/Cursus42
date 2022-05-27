/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:15:01 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/27 15:55:40 by nakawashi        ###   ########.fr       */
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

typedef struct s_book
{
	int		value;
	t_book	*prev;
	t_book	*next;
}	t_book;

typedef struct s_stack
{
	int		size;
	t_book	*first;
	t_book	*last;
}	t_stack;

#endif
