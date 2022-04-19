/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:30:50 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/19 13:45:11 by lgenevey         ###   ########.fr       */
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
	t_assets ass;
	char	**table;

	table = read_map(file);
	if (!table)
	{
		ft_printf("pas de fichier lisible\n");
		return (0);
	}
	if (!check_img_extension(file, extension))
	{
		ft_printf("Mauvaise extension\n");
		return (0);
	}
	if (!is_rectangle(&map, table))
	{
		ft_printf("Map pas rectangulaire\n");
		return (0);
	}
	if (!check_walls_around(&map, table))
	{
		ft_printf("Pas que des 1 autour\n");
		return (0);
	}
	if (!check_assets(table, &ass))
	{
		printf("Mauvaises lettres dans la map\n");
		return (0);
	}
	return (1);
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
int	check_walls_around(t_map *map, char **file)
{
	int	i;
	int	j;

	map->rows_nb = 0;
	while (file[map->rows_nb]) // get number of lines == height
		map->rows_nb++;
	j = 0;
	while (file[j])
	{
		i = 0;
		while (file[j][i])
		{
			if ((j == 0 || j == map->rows_nb - 1
			|| i == 0 || i == map->line_lenght - 1)
			&& (file[j][i] != '1'))
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
	char **file :	2D array that contains the map.
*/
int	is_rectangle(t_map *map, char **table)
{
	int	current_line;
	int	i;

	map->line_lenght = ft_strlen(table[0]); //13
	i = 1;
	while(table[i]) // strings
	{
		current_line = ft_strlen(table[i]);
		if (map->line_lenght == current_line)
			i++;
		else
			return (0);
	}
	return (1);
}

// check si on a bien 01PEC
int	check_assets(char **table, t_assets *ass)
{
	int		i;
	int		j;

	i = 0;
	while (table[i]) //search line per line
	{
		j = 0;
		while (table[i][j]) // search char per char
		{
			if (table[i][j] == 'P' || table[i][j] == 'E' || table[i][j] == 'C'
			|| table[i][j] == '1' || table[i][j] == '0')
			{
				if (table[i][j] == 'P')
					ass->P++;
				else if (table[i][j] == 'E')
					ass->E++;
				else if (table[i][j] == 'C')
					ass->C++;
			}
			else
				return (0);
			j++;
		}
		i++;
	}
	if (ass->P == 1 && ass->E == 1 && ass->C > 0)
		return (1);
	return(0);
}





// #include <unistd.h>

// int	main(int argc, char **argv)
// {
// 	char	table[128];
// 	int		i, j;

// 	if (argc == 3)
// 	{
// 		i = 0;
// 		while (table[i])
// 		{
// 			table[i] = 0;
// 			i++;
// 		}
// 		i = 2;
// 		while (i > 0)
// 		{
// 			j = 0;
// 			while (argv[i][j])
// 			{
// 				if (i == 2 && !table[(unsigned char)argv[i][j]])
// 					table[(unsigned char)argv[i][j]] = 1;
// 				else if (i == 1 && table[(unsigned char)argv[i][j]] == 1)
// 				{
// 					write(1, &argv[i][j], 1);
// 					table[(unsigned char)argv[i][j]] = 2;
// 				}
// 				j++;
// 			}
// 			i--;
// 		}
// 	}
// 	write(1, "\n", 1);
// 	return (0);
//}