/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:05:41 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/08 20:34:26 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

/*
	put content of the file inside map
	then split each line in **map
*/
int	**read_map(char *path_to_file)
{
	int		fd;
	char	*line;
	char	**map;

	fd = open(path_to_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (fd > 0)
	{
		// get next line pour lire et mettre la ligne dans line et finir avec un tableaau a deux dim
		map = get_next_line(fd);
		while (map)
		{
			ft_printf("map before:	%s\n", map);
			map = get_next_line(fd);
		}
		map = ft_split(map, '\n');
	}
	free(map);
	close(fd);
	return (map);
}

