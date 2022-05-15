/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:59:31 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/15 02:27:37 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves_in_window(t_game *game)
{
	char	*str;

	mlx_string_put(game->mlx_id, game->win_id, 6, game->win_height + 12, 0x00FFFFFF, "Moves : ");
	str = ft_itoa(game->player.nb_movements);
	mlx_string_put(game->mlx_id, game->win_id, IMG_SIZE, game->win_height + 12, 0x00FFFFFF, str);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	move_up(game);
	else if (keycode == KEY_A)
	move_left(game);
	else if (keycode == KEY_S)
	move_down(game);
	else if (keycode == KEY_D)
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
