/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 09:37:30 by lgenevey          #+#    #+#             */
/*   Updated: 2021/10/12 09:51:50 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}