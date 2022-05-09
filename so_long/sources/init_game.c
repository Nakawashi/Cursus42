/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:27:56 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/09 18:36:34 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	initialize game datas
*/
static void	init_game(t_game *game)
{
	game->mlx_id = mlx_init();
	game->win_id = mlx_new_window(game->mlx_id, 500, 500, "Half Life 3");
	game->collectable = 0;
	game->end_game = 0;
}

/*
	init img facilitator
*/
static void	*init_img(char *img_path, t_game *game)
{
	void	*img_id;

	img_id = mlx_xpm_file_to_image
		(game->mlx_id, img_path, &game->img_height, &game->img_height);
	return (img_id);
}

/*
	initialize images
*/
static void	put_img(t_game *game)
{
	game->img_ground = init_img(GROUND_PATH, game);
	game->img_wall = init_img(WALL_PATH, game);
	game->img_collectible = init_img(COLLECTIBLE_PATH, game);
	game->img_exit = init_img(EXIT_PATH, game);
	game->img_player_w = init_img(PLAYERW_PATH, game);
	game->img_player_a = init_img(PLAYERA_PATH, game);
	game->img_player_s = init_img(PLAYERS_PATH, game);
	game->img_player_d = init_img(PLAYERD_PATH, game);
}

void	img_draw(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx_id, game->win_id, img, x * IMG_SIZE, y * IMG_SIZE);
}

static void	map_init_hook_c(t_game *game, int j, int i)
{
	img_draw(game, game->img_collectible, j, i);
	game->collectable++;
}

static void	map_init_hook_p(t_game *game, int j, int i)
{
	img_draw(game, game->img_player_s, j, i);
	game->x = j;
	game->y = i;
}
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

void	game_init(t_game *game)
{
	init_game(game);
	put_img(game);
	map_init(game);
}