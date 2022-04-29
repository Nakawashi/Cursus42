/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:02:28 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/29 17:49:22 by nakawashi        ###   ########.fr       */
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
}	t_game;

# define SPRITE_SIZE 48

// ascii code for each lowercase letter and arrow
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

# define WALL "assets/images/1_wall.xpm"
# define GROUND "assets/images/0_ground.xpm"
# define PLAYER "assets/images/P_hero.xpm"
# define EXIT "assets/images/E_exit.xpm"
# define COLLECTIBLE "assets/images/C_item.xpm"

void	init_game(t_game *game);
int		map_check(const char *file, t_game *game);
char	**read_map(const char *path_to_file);
void	free_map(char **map);

int	deal_key(int key, void *param);


#endif
