/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:05:41 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/29 17:31:20 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

/*
	Read the .ber map and saves it on map.map which is a 2 dimension table.
*/
char	**read_map(const char *path_to_file)
{
	int		fd;
	char	*line;
	char	*saved;
	char	**map;

	map = NULL;
	fd = open(path_to_file, O_RDONLY);
	if (fd < 0)
		return (0);
	if (fd > 0)
	{
		saved = ft_strdup("");
		while(1)
		{
			line = get_next_line(fd);
			if (!line)
				break;
			saved = ft_strjoin_free(saved, line);
			//ft_printf("saved : \n%s\n", saved);
			free(line);
		}
		map = ft_split(saved, '\n');
		free(saved);
	}
	close(fd);
	return (map);
}

