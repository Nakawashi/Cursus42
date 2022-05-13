/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:29:16 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/13 15:40:13 by lgenevey         ###   ########.fr       */
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
	//ft_printf("ESC used to quit\n");
	mlx_destroy_image(game->mlx_id, game->img_ground);
	mlx_destroy_image(game->mlx_id, game->img_wall);
	mlx_destroy_image(game->mlx_id, game->img_collectible);
	mlx_destroy_image(game->mlx_id, game->img_exit);
	mlx_destroy_image(game->mlx_id, game->img_player_w);
	mlx_destroy_image(game->mlx_id, game->img_player_a);
	mlx_destroy_image(game->mlx_id, game->img_player_s);
	mlx_destroy_image(game->mlx_id, game->img_player_d);
	free_map(game->map);
	//ft_printf("map[1] ; %s\n", game->map[1]);
	mlx_destroy_window(game->mlx_id, game->win_id);
	return (0);
}