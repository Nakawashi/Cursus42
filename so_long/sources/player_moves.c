/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:07:39 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/14 19:09:21 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	ft_printf("aller en haut\n");
	ft_printf("actual position of P: game->map[%d][%d]\n", game->player.index_i, game->player.index_j);
	game->map[game->player.index_i - 1][game->player.index_j] = 'P';
	game->player.direction = 'w';
	game->end_game = 0;
}

void	move_left(t_game *game)
{
	ft_printf("aller a gauche\n");
	game->collected++;
	game->player.direction = 'a';
}

void	move_down(t_game *game)
{
	ft_printf("aller en bas\n");
	game->collected++;
	game->player.direction = 's';
}

void	move_right(t_game *game)
{
	ft_printf("aller a droite\n");
	game->collected++;
	game->player.direction = 'd';
}

// selon ce sur quoi on va il faut aller dessus et nettoyer les deux cases concernees

