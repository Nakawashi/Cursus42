/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_items.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:41:04 by nakawashi         #+#    #+#             */
/*   Updated: 2022/05/16 14:22:12 by lgenevey         ###   ########.fr       */
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

/*
	We don't want E being replaced by 0
*/
void	handle_0(t_game *game, int i, int j)
{
	if (game->map[game->player.index_i][game->player.index_j] == EXIT)
	{
		swap_value(
			&game->map[game->player.index_i][game->player.index_j],
			&game->map[i][j], 'E', 'P');
	}
	else
	{
		swap_value(
			&game->map[game->player.index_i][game->player.index_j],
			&game->map[i][j], '0', 'P');
	}
	game->player.nb_movements++;
}

/*
	in case next move is on a collectible
	i and j are the new position depending on direction
	here I define if we show the EXIT
*/
void	handle_c(t_game *game, int i, int j)
{
	if (game->map[game->player.index_i][game->player.index_j] == EXIT)
	{
		swap_value(
			&game->map[game->player.index_i][game->player.index_j],
			&game->map[i][j], 'E', 'P');
	}
	else
	{
		swap_value(
			&game->map[game->player.index_i][game->player.index_j],
			&game->map[i][j], '0', 'P');
	}
	game->collected++;
	game->player.nb_movements++;
	if (game->collected == game->count_c)
	{
		img_draw(game, game->img_exit, game->exit_index_j, game->exit_index_i);
		game->end_game = 1;
	}
}

void	handle_e(t_game *game)
{
	game->player.nb_movements++;
	if (game->end_game)
	{
		ft_printf("Termine en %d deplacements !\n", game->player.nb_movements);
		clean(game);
	}
}
