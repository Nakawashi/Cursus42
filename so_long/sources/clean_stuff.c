/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:29:16 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/09 15:10:36 by lgenevey         ###   ########.fr       */
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
	ft_printf("ESC used to quit\n");
	// mlx_destroy_image(game->mlx_id, game->img_wall);
	// mlx_destroy_image(game->mlx_id, game->img_ground);
	// mlx_destroy_image(game->mlx_id, game->img_player);
	// mlx_destroy_image(game->mlx_id, game->img_coll);
	// mlx_destroy_image(game->mlx_id, game->img_exit);
	//free_map(game->map);
	ft_printf("map[1] ; %s\n", game->map[1]);
	free(game->map);
	mlx_destroy_window(game->mlx_id, game->win_id);
	exit(0);
}