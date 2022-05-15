/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_items.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:41:04 by nakawashi         #+#    #+#             */
/*   Updated: 2022/05/15 13:42:43 by nakawashi        ###   ########.fr       */
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

void	handle_0(t_game *game, int i, int j)
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
void	handle_c(t_game *game, int i, int j)
{
	swap_value(
		&game->map[game->player.index_i][game->player.index_j],
		&game->map[i][j], '0', 'P');
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
		ft_printf("Vous avez termine en %d deplacements !\n", game->player.nb_movements);
		clean(game);
	}
}
