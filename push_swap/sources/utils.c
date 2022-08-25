/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:29:32 by nakawashi         #+#    #+#             */
/*   Updated: 2022/07/02 19:54:28 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	in a char **, returns nb of arrays in a pointer of arrays
*/
int	ft_count_arrays(char **array)
{
	int	count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	get_nb_chunks(int size)
{
	if (size <= 100)
		return (5);
	if (size > 100 && size <= 400)
		return (10);
	if (size > 400)
		return (12);
	return (-1);
}

/*
	atoi, but prints Error if INT overflow
*/
int	ft_atoi_check_overflow(char *str)
{
	int		i;
	long	v;
	int		sign;

	i = 0;
	v = 0;
	sign = 1;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		v += str[i] - 48;
		v *= 10;
		i++;
	}
	v = (v * sign) / 10;
	if (v > INT_MAX || v < INT_MIN)
		print_error_free_and_exit(str);
	return (v);
}
