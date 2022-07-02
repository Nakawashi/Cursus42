/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 23:47:51 by nakawashi         #+#    #+#             */
/*   Updated: 2022/07/02 18:00:06 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	codes: (not used here)
	0 - param non numériques
	1 - param incluant des doublons
	2 - int overflow
*/
void	print_error_freeppointer_and_exit(char **str)
{
	ft_free_ppointer(str);
	ft_putendl_fd("Error", 2);
	exit(0);
}

void	print_error_free_and_exit(char *str)
{
	free(str);
	ft_putendl_fd("Error", 2);
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
