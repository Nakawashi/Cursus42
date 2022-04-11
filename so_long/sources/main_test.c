#include "get_next_line.h"
#include "so_long.h"
#include <stdio.h>
// run this :
// gcc main_test.c ../libraries/libft/libft.a ../libraries/libft/ft_printf/libftprintf.a get_next_line_utils.c get_next_line.c

/*
	Lis la carte donnee en parametres et la stock dans un tableau
	a deux dimensions
*/
char	**read_map(const char *path_to_file)
{
	int		fd;
	char	*line;
	char	*saved;
	char	**map;

	fd = open(path_to_file, O_RDONLY);
	if (fd < 0)
		ft_printf("Error : can't find a file");
	if (fd > 0)
	{
		saved = ft_strdup(""); // si s1 vide join return null
		while(1)
		{
			line = get_next_line(fd);
			if (!line)
				break;
			saved = ft_strjoin_free(saved, line);
			ft_printf("saved : \n%s\n", saved);
			free(line);
		}
		map = ft_split(saved, '\n');
		free(saved);
	}
	close(fd);
	return (map);
}

/*
	if each line has same nb of char, it's a rectangle
	compare all lines with the first (map->line_lenght)
*/
int	is_rectangle(t_map *map, char **file)
{
	int	current_line;
	int	i;

	map->line_lenght = ft_strlen(file[0]); //13
	//ft_printf("line_lenght :	%d\n", map->line_lenght);
	i = 1;
	while(file[i]) // strings
	{
		current_line = ft_strlen(file[i]);
		//ft_printf("current_line :	%d\n", current_line);
		if (map->line_lenght == current_line)
			i++;
		else
			return (0);
	}
	//ft_printf("file[i] :	%s\n", file[i]); le tableau est NULL termiated
	return (1);
}

/*
	first and last line should be 1
	first and last char per line should be 1
	had to intervert j and i to check horizontally :D
*/
int	check_walls_around(t_map *map, char **file)
{
	int	i;
	int	j;

	map->rows_nb = 0;
	while (file[map->rows_nb])
		map->rows_nb++;
	ft_printf("map->rows_nb :		%d\n", map->rows_nb);
	ft_printf("map->line_lenght :	%d\n", map->line_lenght);
	j = 0;
	while (j < map->rows_nb)
	{
		i = 0;
		while (file[j][i])
		{
			//ft_printf("file[j][i]		%c\n", file[j][i]);
			if (((j == 0 || j == map->rows_nb) || (i == 0 || i == map->line_lenght)) && (file[j][i] != '1'))
			{
				ft_printf("erreur pas que des 1 au premier et dernier char\n");
				return (0);
			}
			ft_printf("j :	%d\n", j);
			ft_printf("j :	%d\n", j);
			ft_printf("file[j][i] :	%c\n", file[j][i]);
			ft_printf("file[j] :	%c\n", file[j]); // probleme ici je rentre pas dans la boucle si le X est en bas a gauche
			i++;
		}
		j++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	map;
	char	**table;

	table = read_map(argv[1]);
	is_rectangle(&map, table);
	check_walls_around(&map, table);
	return (0);
}