/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:59:31 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/13 17:57:01 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_hook(int keycode, t_game *game)
{
	printf("nb_movements 3 : %d\n", game->nb_movements);

	if (keycode == ESC)
		{
			clean(game);
			return (0);
		}
	if (keycode == KEY_A)
	{
		printf("movements before : %d\n", game->nb_movements);
		game->nb_movements++;
		printf("movements after : %d\n", game->nb_movements);
		game->player_direction = 'a';
	}
	if (keycode == KEY_W)
	{
		game->player_direction = 'w';
	}
	if (keycode == KEY_S)
	{

	}
	if (keycode == KEY_D)
	{

	}
	return (0);
}

/*
	mlx_key_hook : handle ESC, W, A, S, D
	mlx_hook : handle quit by closing window
*/
void	game_hooks(t_game *game)
{
	mlx_key_hook(game->win_id, key_hook, &game);
	mlx_hook(game->win_id, 17, 1L << 5, clean, &game);
}
