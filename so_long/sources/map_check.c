/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:30:50 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/13 17:24:22 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	first and last line should be 1
	first and last char per line should be 1
	had to intervert j and i to check horizontally :D

	t_map *map :	reference of struct s_map, init in map_check()
*/
static int	check_walls_around(t_game *game)
{
	int	i;
	int	j;

	if (!game->map)
		return(0);
	while (game->map[game->map_height]) // get number of lines == height
		game->map_height++;
	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if ((j == 0 || j == game->map_height - 1 || i == 0
					|| i == game->map_width - 1) && (game->map[j][i] != '1'))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

/*
	if each line has same nb of char, it's a rectangle
	compare all lines with the first (map->line_lenght)

	t_map *map :	reference of struct s_map, init in map_check()
*/
static int	is_rectangle(t_game *game)
{
	int	current_line;
	int	i;

	if (!game->map)
		return(0);
	game->map_width = ft_strlen(game->map[0]); //13
	i = 1;
	while (game->map[i]) // strings
	{
		current_line = ft_strlen(game->map[i]);
		if (game->map_width == current_line)
			i++;
		else
			return (0);
	}
	return (1);
}

/*
	combined with check_assets below
*/
static int	compare_assets(t_game *game, int i, int j)
{
	if (!game->map)
		return(0);
	if (game->map[i][j] == 'P' || game->map[i][j] == 'E'
			|| game->map[i][j] == 'C' || game->map[i][j] == '1'
				|| game->map[i][j] == '0')
	{
		if (game->map[i][j] == 'P')
			{
				game->count_P++;
				ft_printf("game->count_P : %d\n", game->count_P);
			}
		else if (game->map[i][j] == 'E')
			{
				game->count_E++;
				ft_printf("game->count_E : %d\n", game->count_E);
			}
		else if (game->map[i][j] == 'C')
			{
				game->count_C++;
				ft_printf("game->count_C : %d\n", game->count_C);
			}
	}
	else
		{
			ft_printf("Lettre non identifiable dans la map\n");
			return (0);
		}
	return (1);
}

/*
	check letters in map
*/
static int	check_assets(t_game *game)
{
	int		i;
	int		j;

	if (!game->map)
		return(0);
	i = 0;
	while (game->map[i]) //search line per line
	{
		j = 0;
		while (game->map[i][j]) // search char per char
		{
			if (!compare_assets(game, i, j))
				return(0);
			j++;
			//ft_printf("j : %d\n", j);
		}
		i++;
		//ft_printf("i : %d\n", i);
	}
	if (game->count_P == 1 && game->count_E == 1 && game->count_C > 0)
		return (1);
	return (0);
}

/*
	Used in main file
	I took the decision to hardcode nb of extension's letters + '\0'
	xlsx or docx would not work here, but it's easy to update
	Remember : ft_strncmp returns 0 if both are the same

	const char *file_path :	(../assets/map/filename.ber)
	char *extension :		dot + file extension = ".ber"
*/
static int	check_ext(const char *file_path, char *extension)
{
	char	*new_ext;
	if (!file_path)
		return (0);
	new_ext = ft_strrchr(file_path, '.');
	if (ft_strncmp(new_ext, extension, 5))
		return (0);
	return (1);
}

/*
	Combine all requirement for map parsing
	- Correct .ber extension
	- Walls around the map
	- At least 4 lines, 4 columns to be coherent (square)
	- Each asked items (E, P, C, 0, 1)
*/
int	map_check(const char *file, t_game *game)
{
	game->count_P = 0;
	game->count_E = 0;
	game->count_C = 0;
	game->map = read_map(file);
	if (check_ext(file, ".ber") && is_rectangle(game)
			&& check_walls_around(game) && check_assets(game))
		return (1);
	else
	{
		if (!check_ext(file, ".ber"))
			ft_printf("Mauvaise extension\n");
		if (!is_rectangle(game))
			ft_printf("Map pas rectangulaire\n");
		if (!check_walls_around(game))
			ft_printf("Pas que des 1 autour\n");
		if (!check_assets(game))
			ft_printf("Pas le bon compte d'elements dans la map\n");
	}
	return (0);
}
