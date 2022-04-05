/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:30:50 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/05 15:00:00 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
    Combine all requirement for map parsing
    - Correct .ber extension
    - At least 4 lines, 4 columns to be coherent (square)
    - Walls around the map
    - Each asked items (E, P, C, 0, 1)
*/
int	map_check(const char *s)
{
	return (0);
}

/*
    Used in main file
    I took the decision to hardcode nb of extension's letters
    xlsx or docx would not work here, but it's easy to update
	Remember : ft_strncmp returns 0 if both are the same
*/
int	check_img_extension(const char *filename, char *extension)
{
	char	*new_ext;

	if (!filename)
		return (0);
	new_ext = ft_strrchr(filename, '.');
	if (ft_strncmp(new_ext, extension, 5))
		return (0);
	return (1);
}

/*
    We want walls all around the map
*/
int	check_walls_around(char *s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[j])
		{
			j++;
		}
		i++;
	}
	return (1);
}
