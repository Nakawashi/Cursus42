/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:07:39 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/15 13:44:08 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Check which item is where we go
	Change player direction img
	Change new position player index
*/
void	move_up(t_game *game)
{
	int	i;
	int	j;

	i = game->player.index_i - 1;
	j = game->player.index_j;
	if (game->map[i][j] != WALL)
	{
		if (game->map[i][j] == EXIT)
			handle_e(game);
		else if (game->map[i][j] == COLLECTIBLE)
			handle_c(game, i, j);
		else if (game->map[i][j] == GROUND)
			handle_0(game, i, j);
		else
		img_draw(game, game->img_player_w, j, i);
		img_draw(game, game->img_ground, game->player.index_j, game->player.index_i);
		game->player.index_i--;
	}
	img_draw(game, game->img_player_w, game->player.index_j, game->player.index_i);
}

void	move_left(t_game *game)
{
	int	i;
	int	j;

	i = game->player.index_i;
	j = game->player.index_j - 1;
	if (game->map[i][j] != WALL)
	{
		if (game->map[i][j] == EXIT)
			handle_e(game);
		else if (game->map[i][j] == COLLECTIBLE)
			handle_c(game, i, j);
		else if (game->map[i][j] == GROUND)
			handle_0(game, i, j);
		img_draw(game, game->img_player_a, j, i);
		img_draw(game, game->img_ground, game->player.index_j, game->player.index_i);
		game->player.index_j--;
	}
	img_draw(game, game->img_player_a, game->player.index_j, game->player.index_i);
}

void	move_down(t_game *game)
{
	int	i;
	int	j;

	i = game->player.index_i + 1;
	j = game->player.index_j;
	if (game->map[i][j] != WALL)
	{
		if (game->map[i][j] == EXIT)
			handle_e(game);
		else if (game->map[i][j] == COLLECTIBLE)
			handle_c(game, i, j);
		else if (game->map[i][j] == GROUND)
			handle_0(game, i, j);
		img_draw(game, game->img_player_s, j, i);
		img_draw(game, game->img_ground, game->player.index_j, game->player.index_i);
		game->player.index_i++;
	}
	img_draw(game, game->img_player_s, game->player.index_j, game->player.index_i);
}

void	move_right(t_game *game)
{
	int	i;
	int	j;

	i = game->player.index_i;
	j = game->player.index_j + 1;
	if (game->map[i][j] != WALL)
	{
		if (game->map[i][j] == EXIT)
			handle_e(game);
		else if (game->map[i][j] == COLLECTIBLE)
			handle_c(game, i, j);
		else if (game->map[i][j] == GROUND)
			handle_0(game, i, j);
		img_draw(game, game->img_player_d, j, i);
		img_draw(game, game->img_ground, game->player.index_j, game->player.index_i);
		game->player.index_j++;
	}
	img_draw(game, game->img_player_d, game->player.index_j, game->player.index_i);
}
