/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:29:32 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/23 19:13:22 by lgenevey         ###   ########.fr       */
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

/*
	atoi, but prints Error if INT overflow
*/
int	ft_atoi_check_overflow(const char *str)
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
		print_error_and_exit();
	return (v);
}

/*
	free ppointer
*/
void	ft_free_array(char **array)
{
	int	i;

	if (array)
	{
		i = 0;
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

void	print_stack(t_stack *a, t_stack *b)
{
	printf("-- Liste A --\n");
	while (a->top)
	{
		printf("liste dans l'ordre : [%d]\n", *((int *)a->top->content));
		a->top = a->top->next;
	}
	printf("\n");
	printf("-- Liste B --\n");
	while (b->top)
	{
		printf("liste dans l'ordre : [%d]\n", *((int *)b->top->content));
		b->top = b->top->next;
	}
	printf("\n");
}
