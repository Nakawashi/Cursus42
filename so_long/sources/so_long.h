/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:02:28 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/25 13:35:36 by nakawashi        ###   ########.fr       */
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

typedef struct s_window
{
	void	*mlx_id;
	void	*win_id;
	int		win_width;
	int		win_height;
}	t_window;

typedef struct s_map
{
	char	**map;
	int		line_lenght;
	int		rows_nb;
	int		count_P;
	int 	count_E;
	int		count_C;

}	t_map;

typedef struct s_img
{
	void	*img_id;

}	t_img;

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

void	window_init(t_window *window);
void	map_init(t_map *map);
void	img_init(t_img *img);

int		map_check(const char *file, char *extension, t_map *map);
char	**read_map(const char *path_to_file);
void	free_map(char **map);

#endif
