/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:30:50 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/09 12:15:55 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
    Combine all requirement for map parsing
    - Correct .ber extension
    - Walls around the map
    - At least 4 lines, 4 columns to be coherent (square)
    - Each asked items (E, P, C, 0, 1)
*/
int	map_check(const char *file, char *extension)
{
	if (check_img_extension(file, extension) && check_walls_around(file)
		&& check_if_square(file) && check_assets(file))
		return (1);
	return (0);
}

/*
    Used in main file
    I took the decision to hardcode nb of extension's letters
    xlsx or docx would not work here, but it's easy to update
	Remember : ft_strncmp returns 0 if both are the same
*/
int	check_img_extension(const char *file, char *extension)
{
	char	*new_ext;

	if (!file)
		return (0);
	new_ext = ft_strrchr(file, '.');
	if (ft_strncmp(new_ext, extension, 5))
		return (0);
	return (1);
}

/*
    We want walls all around the map
*/
int	check_walls_around(const char *s)
{
	// check murs donc premiere et derniere ligne sont des 1
	// reste des lignes premier et dernier char sont des 1
	// retourne 1 si ok
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

// pour un carre il doit y avoir le meme nombre de char par ligne
int	check_if_square(const char *file)
{
	return (1);
}

// check si on a bien 01PEC
int	check_assets(const char *file)
{
	return (1);
}
