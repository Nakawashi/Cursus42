/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:02:28 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/11 20:55:57 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libraries/libft/libft.h"
# include "../libraries/libft/ft_printf/ft_printf.h"
# include "../libraries/minilibx/mlx.h"

typedef struct s_window
{
	void	*id;
	int		win_width;
	int		win_height;
}	t_window;

typedef struct s_map
{
	char	**map;
	int		line_lenght;
	int		rows_nb;

}	t_map;

typedef struct s_img
{
	void	*id;

}	t_img;

typedef struct s_player
{

}	t_player;

# define SPRITE_SIZE 48

// ascii code for each lowercase letter
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

int	map_check(const char *file, char *extension);
int	check_img_extension(const char *file_path, char *extension);
int	check_walls_around(t_map *map, char **table);
int	is_rectangle(t_map *map, char **table);
int	check_assets(char **table);

char	**read_map(const char *path_to_file);

#endif