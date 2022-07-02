/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_ppointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:23:53 by lgenevey          #+#    #+#             */
/*   Updated: 2022/07/02 17:24:55 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


/*
	Copie et malloc un ppointer
*/
char	**ft_strdup_ppointer(int argc, char **argv)
{
	char	**cpy;
	int		i;

	cpy = malloc(sizeof(char *) * argc);
	i = 0;
	while (argv[i])
	{
		cpy[i] = ft_strdup(argv[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}