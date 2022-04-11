/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:30:50 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/11 20:58:52 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
    Combine all requirement for map parsing
    - Correct .ber extension
    - Walls around the map
    - At least 4 lines, 4 columns to be coherent (square)
    - Each asked items (E, P, C, 0, 1)
*/
int	map_check(const char *file, char *extension)
{
	t_map	map;
	char	**table;

	if (check_img_extension(file, extension))
	{
		table = read_map(file);
		if (!table)
			return (0);
		if (is_rectangle(&map, table) && check_walls_around && check_assets(table))
		{
			return (1);
		}
		else
			return(NOT_RECTANGLE);
	}
	else
		return (ERROR_WRONG_IMG_EXTENSION);
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
int	check_img_extension(const char *file_path, char *extension)
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
	first and last line should be 1
	first and last char per line should be 1
	had to intervert j and i to check horizontally :D

	t_map *map :	reference of struct s_map, init in map_check()
	char **file :	2D array that contains the map.
*/
int	check_walls_around(t_map *map, char **table)
{
	int	i;
	int	j;

	map->rows_nb = 0;
	while (table[map->rows_nb])
		map->rows_nb++;
	// ft_printf("map->rows_nb :		%d\n", map->rows_nb);
	// ft_printf("map->line_lenght :	%d\n", map->line_lenght);
	j = 0;
	while (j < map->rows_nb)
	{
		i = 0;
		while (table[j][i])
		{
			//ft_printf("file[j][i]		%c\n", file[j][i]);
			if (((j == 0 || j == map->rows_nb) && (i == 0 || i == map->line_lenght)) && (table[j][i] != '1'))
			{
				ft_printf("erreur pas que des 1 au premier et dernier char\n");
				return (0);
			}
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
	char **file :	2D array that contains the map.
*/
int	is_rectangle(t_map *map, char **table)
{
	int	current_line;
	int	i;

	map->line_lenght = ft_strlen(table[0]); //13
	ft_printf("line_lenght :	%d\n", map->line_lenght);
	i = 1;
	while(table[i]) // strings
	{
		current_line = ft_strlen(table[i]);
		ft_printf("current_line :	%d\n", current_line);
		if (map->line_lenght == current_line)
			i++;
		else
			return (0);
	}
	return (1);
}

// check si on a bien 01PEC
int	check_assets(char **table)
{
	return (1);
}
