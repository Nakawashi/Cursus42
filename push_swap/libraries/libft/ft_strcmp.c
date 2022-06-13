/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:32:00 by nakawashi         #+#    #+#             */
/*   Updated: 2022/06/13 13:38:07 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	s1 and s2 are compared strings
	return 0 : no difference
	else : return the ascii difference
*/
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] && s2[i]) && (s1[i] == s2[i]))
		i++;
	if ((s1[i] > s2[i]) || (s1[i] < s2[i]))
		return (s1[i] - s2[i]);
	return (0);
}
