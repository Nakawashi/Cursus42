/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:30:50 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/16 19:57:19 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	initialize variables we need in the beeeeginning, for the arg check
	same role for init_game() but i want them to be init only if check passed
*/
static void	variables_init(t_game *game)
{
	game->count_p = 0;
	game->count_e = 0;
	game->count_c = 0;
	game->player.nb_movements = 0;
	game->map_height = 0;
	game->map_width = 0;
}

/*
	Combine all requirement for map checking
	- Correct .ber extension
	- Walls around the map
	- At least 4 lines, 4 columns to be coherent (rectangle, sqares included OK)
	- Each asked items (E, P, C, 0, 1)
*/
int	map_check(const char *file, t_game *game)
{
	variables_init(game);
	game->map = read_map(file);
	if (!game->map)
			{
				ft_printf("Nom de fichier invalide");
				return(0);
			}
	if (check_ext(file, ".ber") && is_rectangle(game)
		&& check_walls_around(game) && check_assets(game))
		return (1);
	else
	{
		if (!check_ext(file, ".ber"))
			ft_printf("Mauvaise extension\n");
		if (!is_rectangle(game))
			ft_printf("Map pas rectangulaire\n");
		if (!check_walls_around(game))
			ft_printf("Pas que des 1 autour\n");
		if (!check_assets(game))
			ft_printf("Pas le bon compte d'elements dans la map\n");
	}
	return (0);
}
