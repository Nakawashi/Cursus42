/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:07:39 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/15 01:58:30 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	swap the value (the char) in the 2D table for actual position and next pos.
*/
static void	swap_value(char *position, char *next_pos, char c, char new_c)
{
	*position = c;
	*next_pos  = new_c;
}

static void	handle_0(t_game *game, int i, int j)
{
	swap_value(
		&game->map[game->player.index_i][game->player.index_j],
		&game->map[i][j], '0', 'P');
	game->player.nb_movements++;
}

/*
	in case next move is on a collectible
	i and j are the new position depending on direction
	here I define if we show the EXIT
*/
static void	handle_c(t_game *game, int i, int j)
{
	swap_value(
		&game->map[game->player.index_i][game->player.index_j],
		&game->map[i][j], '0', 'P');
	game->collected++;
	game->player.nb_movements++;
	if (game->collected == game->count_c)
		img_draw(game, game->img_exit, game->exit_index_j, game->exit_index_i);
}

static void	handle_e(t_game *game)
{
	game->player.nb_movements++;
	clean(game);
}

/*
	gives new values in 2D table
	Check which item is where we go
	- EXIT and we get all collectible : exit game
	- COLLECTIBLE we swap C for 0
	- WALL we dont move and dont invrement nb_movements but change image
	next step : display changes
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
}
