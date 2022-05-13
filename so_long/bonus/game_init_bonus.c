/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:27:56 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/13 14:41:02 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// --------- init game datas

static void	get_window_size(t_game *game)
{
	int	i;

	i = 0;
	game->win_width = ft_strlen(game->map[i]) * IMG_SIZE;
	game->win_height = 0;
	while (game->map[i])
	{
		game->win_height++;
		i++;
	}
	game->win_height *= IMG_SIZE;
}

/*
	initialize structure variables
*/
static void	init_game(t_game *game)
{
	get_window_size(game);
	game->mlx_id = mlx_init();
	game->win_id = mlx_new_window
		(game->mlx_id, game->win_width, game->win_height, "Half Life 3");
	game->nb_movements = 0;
	game->collectible = 0;
	game->count_E = 0;
	game->count_C = 0;
	game->end_game = 0;
}

// --------- init image

/*
	Creator of new XPM images
*/
static void	*new_xpm_img(char *img_path, t_game *game)
{
	void	*img_id;

	img_id = mlx_xpm_file_to_image
		(game->mlx_id, img_path, &game->img_height, &game->img_height);
	return (img_id);
}

/*
	initialize each different img
*/
static void	init_img(t_game *game)
{
	game->img_ground = new_xpm_img(GROUND_PATH, game);
	game->img_wall = new_xpm_img(WALL_PATH, game);
	game->img_collectible = new_xpm_img(COLLECTIBLE_PATH, game);
	game->img_exit = new_xpm_img(EXIT_PATH, game);
	game->img_player_w = new_xpm_img(PLAYERW_PATH, game);
	game->img_player_a = new_xpm_img(PLAYERA_PATH, game);
	game->img_player_s = new_xpm_img(PLAYERS_PATH, game);
	game->img_player_d = new_xpm_img(PLAYERD_PATH, game);
	game->img_player_d = new_xpm_img(PLAYERD_PATH, game);
	game->img_villain = new_xpm_img(VILLAIN_PATH, game);
}

/*
	regroup functions to use in so_long.c
*/
void	game_init(t_game *game)
{
	init_game(game);
	init_img(game);
	map_init(game);
}