/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:15:01 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/20 16:19:59 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libraries/libft/libft.h"
# include "../libraries/libft/ft_printf/ft_printf.h"

/*
	actual is adress of the actual element. Shows also the address of the
	first element. Important to define the start of the list.
*/
typedef struct s_list
{
	t_element *actual;
}	t_list;

/*
	Elements of the list
	int number : what we want to store
	pointeur sur un element du meme type called next.
*/
typedef struct s_element
{
	int	number;
	t_element *next;
	t_element *previous;
}	t_element;

#endif