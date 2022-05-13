/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:59:31 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/13 11:46:14 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	handle when we press ESC
*/
static int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		clean(game);
	return (0);
}

/*
	handle when we close the window
*/
void	game_hooks(t_game *game)
{
	mlx_key_hook(game->win_id, key_hook, &game);
	//mlx_mouse_hook(game->win_id, mouse_hook, &game);
	mlx_hook(game->win_id, 17, 1L << 5,clean, &game);
}
