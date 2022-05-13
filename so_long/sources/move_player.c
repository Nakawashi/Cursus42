/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:07:39 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/13 20:25:07 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	player_init(t_player *player, int x, int y)
{
	player->x = x;
	player->y = y;
	player->x_origin = x;
	player->y_origin = y;
	player->nb_movements = 0;
	player->collects = 0;
	player->previous = GROUND;
	player->direction = KEY_DOWN;
}

void	move_up(t_game *game, t_player *player)
{
	int		x;
	int		y;

	x = player->x;
	y = player->y;
	ft_printf("game->map[y - 1][x]", game->map[y - 1][x]);
	player->direction = KEY_UP;
	if (game->map[y - 1][x] == EXIT)
		clean(game);
	else if (game->map[y - 1][x] != WALL)
	{
		game->map[y][x] = player->previous;
		if (game->map[y - 1][x] == COLLECTIBLE)
		{
			player->collects++;
			player->previous = GROUND;
		}
		game->map[y - 1][x] = PLAYER;
		player->y--;
		player->nb_movements++;
	}
}
