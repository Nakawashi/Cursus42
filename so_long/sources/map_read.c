/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:05:41 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/05 17:44:39 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

/*
	put content of the file inside map
	then split each line in **map_lines
*/
int	**read_map(char *path_to_file)
{
	int		fd;
	char	*map;
	char	**map_lines;

	fd = open(path_to_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (fd > 0)
	{
		map = get_next_line(fd);
		while (map)
		{
			ft_printf("map before:	%s\n", map);
			map = get_next_line(fd);
		}
		map_lines = ft_split(map, '\n');
	}
	ft_printf("map			:	%s\n", map);
	ft_printf("map_lines	:	%s\n", map_lines);
	free(map);
	close(fd);
	return (map_lines);
}
