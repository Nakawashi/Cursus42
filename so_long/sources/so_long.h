/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:02:28 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/22 11:11:06 by lgenevey         ###   ########.fr       */
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

// ascii code for each lowercase letter
# define KEY_W
# define KEY_A
# define KEY_S
# define KEY_D

void	window_init(t_window *window);
void	map_init(t_map *map);
void	img_init(t_img *img);

int	map_check(const char *file, char *extension, t_map *map);
int	check_img_extension(const char *file_path, char *extension);
int	check_walls_around(t_map *map);
int	is_rectangle(t_map *map);
int	check_assets(t_map *map);

char	**read_map(const char *path_to_file);

void	free_map(char **map);

#endif
