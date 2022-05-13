/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:02:28 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/13 14:41:35 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h> // for perror
# include "../libraries/libft/libft.h"
# include "../libraries/libft/ft_printf/ft_printf.h"
# include "../libraries/minilibx/mlx.h"

typedef struct s_game
{
	void	*mlx_id;
	void	*win_id;
	int		win_width;
	int		win_height;
	char	**map;
	int		map_width; // line length
	int		map_height; // number of rows
	int		count_P;
	int 	count_E;
	int		count_C;
	int		img_width;
	int		img_height;
	int		nb_movements;
	void	*img_ground;
	void	*img_wall;
	void	*img_collectible;
	void	*img_exit;
	void	*img_player_w;
	void	*img_player_a;
	void	*img_player_s;
	void	*img_player_d;
	void	*img_villain;
	int		collectible;
	int		x;
	int		y;
	int		end_game;
}	t_game;

/*
	size of my images
*/
# define IMG_SIZE 48

/*
	Quit game
*/
# define ESC 53

// ascii code for each lowercase letter and arrow
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

// relative paths to xpm images
# define WALL_PATH "assets/images/1.xpm"
# define GROUND_PATH "assets/images/0.xpm"
# define PLAYERW_PATH "assets/images/hero_W.xpm"
# define PLAYERA_PATH "assets/images/hero_A.xpm"
# define PLAYERS_PATH "assets/images/hero_S.xpm"
# define PLAYERD_PATH "assets/images/hero_D.xpm"
# define EXIT_PATH "assets/images/E.xpm"
# define COLLECTIBLE_PATH "assets/images/C.xpm"
# define VILLAIN_PATH "assets/images/V.xpm"

void	img_draw(t_game *game, void *img, int x, int y);
int		map_check(const char *file, t_game *game);
void	game_init(t_game *game);
void	map_init(t_game *game);
char	**read_map(const char *path_to_file);
void	free_map(char **map);
void	game_hooks(t_game *game);
int		clean(t_game *game);

#endif
