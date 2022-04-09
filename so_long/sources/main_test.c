#include "get_next_line.h"
#include "so_long.h"
#include <stdio.h>
// run this :
// gcc main_test.c ../libraries/libft/libft.a ../libraries/libft/ft_printf/libftprintf.a get_next_line_utils.c get_next_line.c

/*
	Lis la carte donnee en parametres et la stock dans un tableau
	a deux dimensions qui facilitera l'utilisation plus tard
*/
char	**read_map(const char *path_to_file)
{
	t_map	map;
	int		fd;
	char	*line;
	char	*saved;

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
		map.map = ft_split(saved, '\n'); //printf("map.map :	\n%s\n", map.map[0]);
		free(saved);
	}
	close(fd);
	return (map.map);
}

int	check_walls_around(t_map *map)
{
	// check murs donc premiere et derniere ligne sont des 1
	// reste des lignes premier et dernier char sont des 1
	// retourne 1 si ok
	int	x;
	int	y;

	x = 0;
	ft_printf("map.map[0] : %s", *map[0]->map);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	map;

	map.map = read_map(argv[1]);
	check_walls_around(&map);
	return (0);
}