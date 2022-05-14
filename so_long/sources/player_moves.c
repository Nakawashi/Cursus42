/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:07:39 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/14 18:37:33 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game, t_player *player)
{
	ft_printf("aller en haut\n");
	//game->map[player->index_i - 1][player->index_j] = PLAYER;
	player->direction = 'w';
	game->end_game = 0;
}

void	move_left(t_game *game, t_player *player)
{
	ft_printf("aller a gauche\n");
	game->collected++;
	player->direction = 'w';
}

void	move_down(t_game *game, t_player *player)
{
	ft_printf("aller en bas\n");
	game->collected++;
	player->direction = 'w';
}

void	move_right(t_game *game, t_player *player)
{
	ft_printf("aller a droite\n");
	game->collected++;
	player->direction = 'w';
}

// selon ce sur quoi on va il faut aller dessus et nettoyer les deux cases concernees

