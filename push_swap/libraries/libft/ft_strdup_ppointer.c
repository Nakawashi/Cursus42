/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_ppointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:23:53 by lgenevey          #+#    #+#             */
/*   Updated: 2022/07/02 19:33:49 by lgenevey         ###   ########.fr       */
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
	if (cpy == NULL)
		exit(0);
	i = 0;
	while (argv[i])
	{
		cpy[i] = ft_strdup(argv[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
