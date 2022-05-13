/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:45:17 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/13 20:23:28 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Creates a new image in memory.
	Returns the id of the img we want to manipulate
	void *img is the image initialized in init_img (init_game.c)
	x and y define where the img should be placed in the window
*/
static void	img_draw(t_game *game, void *img, int img_pos_x, int img_pos_y)
{
	mlx_put_image_to_window
		(game->mlx_id, game->win_id, img,
			img_pos_x * IMG_SIZE, img_pos_y * IMG_SIZE);
}

/*
	put collectible img and increments nb of collectible we get
*/
static void	map_init_hook_c(t_game *game, int j, int i)
{
	img_draw(game, game->img_collectible, j, i);
}

static void	map_init_hook_p(t_game *game, int j, int i)
{
	img_draw(game, game->img_player_s, j, i);
}

/*
	display *img according to the char in the map (01PEC)
*/
void	map_init(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				img_draw(game, game->img_wall, j, i);
			else if (game->map[i][j] == '0')
				img_draw(game, game->img_ground, j, i);
			else if (game->map[i][j] == 'C')
				map_init_hook_c(game, j, i);
			else if (game->map[i][j] == 'E')
				img_draw(game, game->img_exit, j, i);
			else if (game->map[i][j] == 'P')
				map_init_hook_p(game, j, i);
			j++;
		}
		i++;
	}
}