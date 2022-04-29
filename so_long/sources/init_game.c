/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:27:56 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/29 17:30:02 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Parce qu'il faut bien initialiser les variables avant utilisation
*/
void	init_game(t_game *game)
{
	game->mlx_id = mlx_init();
	game->win_id = mlx_new_window(game->mlx_id, 500, 500, "Half Life 3");
	game->win_width = 0;
	game->win_height = 0;
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->count_P = 0;
	game->count_E = 0;
	game->count_C = 0;
	game->img_id = 0;
}
