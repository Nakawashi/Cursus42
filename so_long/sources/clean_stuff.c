/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:29:16 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/16 00:00:02 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	clean(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx_id, game->img_ground);
	mlx_destroy_image(game->mlx_id, game->img_wall);
	mlx_destroy_image(game->mlx_id, game->img_collectible);
	mlx_destroy_image(game->mlx_id, game->img_exit);
	mlx_destroy_image(game->mlx_id, game->img_player_w);
	mlx_destroy_image(game->mlx_id, game->img_player_a);
	mlx_destroy_image(game->mlx_id, game->img_player_s);
	mlx_destroy_image(game->mlx_id, game->img_player_d);
	mlx_destroy_window(game->mlx_id, game->win_id);
	exit (0);
}
