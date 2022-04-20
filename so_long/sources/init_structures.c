/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:27:56 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/20 20:05:38 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Parce qu'il faut bien initialiser les variables avant utilisation
*/

void	window_init(t_window *window)
{
	window->id = NULL;
	window->win_height = 0;
	window->win_width = 0;
}

void	map_init(t_map *map)
{
	map->map = NULL;
	map->line_lenght = 0;
	map->rows_nb = 0;
}

void	game_init(t_game *game)
{
	game->count_P = 0;
	game->count_E = 0;
	game->count_C = 0;
}

