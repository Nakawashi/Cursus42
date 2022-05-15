/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:02:28 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/15 13:42:16 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h> // for perror
# include "../libraries/libft/libft.h"
# include "../libraries/libft/ft_printf/ft_printf.h"
# include "../libraries/minilibx/mlx.h"

enum e_assets
{
	GROUND = '0',
	WALL = '1',
	PLAYER = 'P',
	EXIT = 'E',
	COLLECTIBLE = 'C'
};

typedef struct s_player
{
	int			index_i;
	int			index_j;
	int			nb_movements;
}	t_player;

typedef struct s_game
{
	void		*mlx_id;
	void		*win_id;
	int			win_width;
	int			win_height;
	char		**map;
	int			map_width; // line length
	int			map_height; // number of rows
	int			count_p;
	int			count_e;
	int			count_c; // total of 'C' in map
	int			collected; // nb of collectibles collected
	int			img_width;
	int			img_height;
	void		*img_ground;
	void		*img_wall;
	void		*img_collectible;
	void		*img_exit;
	void		*img_player_w;
	void		*img_player_a;
	void		*img_player_s;
	void		*img_player_d;
	int			img_pos_x;
	int			mg_pos_y;
	int			exit_index_i;
	int			exit_index_j;
	int			end_game;
	t_player	player;
}	t_game;

// size of my images
# define IMG_SIZE 48

// Quit game
# define ESC 53

// text coloration
# define G_FAV 0x008700af
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000

// ascii code for each lowercase letter and arrow
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

// relative paths to xpm images
# define WALL_PATH "assets/images/1.xpm"
# define GROUND_PATH "assets/images/0.xpm"
# define PLAYERW_PATH "assets/images/hero_W.xpm"
# define PLAYERA_PATH "assets/images/hero_A.xpm"
# define PLAYERS_PATH "assets/images/hero_S.xpm"
# define PLAYERD_PATH "assets/images/hero_D.xpm"
# define COLLECTIBLE_PATH "assets/images/C.xpm"
# define EXIT_PATH "assets/images/E.xpm"

char	**read_map(const char *path_to_file);
void	game_init(t_game *game);
void	map_init(t_game *game);
void	game_hooks(t_game *game);
void	handle_0(t_game *game, int i, int j);
void	handle_c(t_game *game, int i, int j);
void	handle_e(t_game *game);
void	move_up(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	free_map(char **map);
void	img_draw(t_game *game, void *img, int img_pos_x, int img_pos_y);
int		map_check(const char *file, t_game *game);
int		clean(t_game *game);

#endif
