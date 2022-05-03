/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:02:28 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/03 16:45:02 by lgenevey         ###   ########.fr       */
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
	void	*img_id;
	void	*img_wall;
	void	*img_ground;
	void	*img_player;
	void	*img_exit;
	void	*img_coll;
	int		p_w; // player position x
	int		p_h; // player position y
}	t_game;

# define SPRITE_SIZE 48

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

# define WALL_PATH "assets/images/1_wall.xpm"
# define GROUND_PATH "assets/images/0_ground.xpm"
# define PLAYER_PATH "assets/images/P_hero.xpm"
# define EXIT_PATH "assets/images/E_exit.xpm"
# define COLLECTIBLE_PATH "assets/images/C_item.xpm"

void	init_game(t_game *game);
int		map_check(const char *file, t_game *game);
char	**read_map(const char *path_to_file);
void	free_map(char **map);
void	game_hooks(t_game *game);
int		deal_key(int key, void *param);
int		clean(t_game *game);


#endif
