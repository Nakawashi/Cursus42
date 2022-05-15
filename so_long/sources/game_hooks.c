/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:59:31 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/15 13:55:46 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_moves_in_window(t_game *game)
{
	char	*str;

	mlx_string_put(game->mlx_id, game->win_id, 15, game->win_height + 18, G_FAV, "Mouvements : ");
	str = ft_itoa(game->player.nb_movements);
	mlx_string_put(game->mlx_id, game->win_id, 105, game->win_height + 18, WHITE, str);
	ft_printf("Mouvements : %s\n", str);
}

static int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		move_up(game);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(game);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(game);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(game);
	if (keycode == ESC)
		clean(game);
	display_moves_in_window(game);
	return (0);
}

/*
	mlx_key_hook : handle ESC, W, A, S, D
	mlx_hook : handle quit by closing window
*/
void	game_hooks(t_game *game)
{
	mlx_key_hook(game->win_id, key_hook, game);
	mlx_hook(game->win_id, 17, 0, clean, game);
}
