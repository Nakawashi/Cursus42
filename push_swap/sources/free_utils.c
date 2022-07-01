/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 23:47:51 by nakawashi         #+#    #+#             */
/*   Updated: 2022/07/01 23:48:13 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	codes: (not used here)
	0 - param non numériques
	1 - param incluant des doublons
	2 - int overflow
*/
void	print_error_and_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

void	free_ppointer_num_and_exit(char **str, int *num)
{
	ft_free_ppointer(str);
	free(num);
	exit(0);
}

void	free_ppointer_and_exit(char **str)
{
	ft_free_ppointer(str);
	exit(0);
}

void	free_all_and_exit(char **str, int *num1, int *num2)
{
	ft_free_ppointer(str);
	free(num1);
	free(num2);
	exit(0);
}
