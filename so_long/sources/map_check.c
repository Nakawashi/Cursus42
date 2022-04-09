/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:30:50 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/09 17:23:02 by lgenevey         ###   ########.fr       */
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
int	map_check(const char *map, char *extension)
{
	if (check_img_extension(map, extension) && check_walls_around(map)
		&& check_if_square(map) && check_assets(map))
		return (1);
	return (0);
}

/*
    Used in main file
    I took the decision to hardcode nb of extension's letters + '\0'
    xlsx or docx would not work here, but it's easy to update
	Remember : ft_strncmp returns 0 if both are the same
*/
int	check_img_extension(const char *map, char *extension)
{
	char	*new_ext;

	if (!map)
		return (0);
	new_ext = ft_strrchr(map, '.');
	if (ft_strncmp(new_ext, extension, 5))
		return (0);
	return (1);
}

/*
    We want walls all around the map
*/
int	check_walls_around(char **map)
{
	// check murs donc premiere et derniere ligne sont des 1
	// reste des lignes premier et dernier char sont des 1
	// retourne 1 si ok
	int	x;
	int	y;

	x = 0;
	while (&map[x][y])
	{
		y = 0;
		while (&map[x][y])
		{
			y++;
		}
		x++;
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
