/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:05:41 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/09 13:47:37 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

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
		saved = ft_strdup("");
		while(1)
		{
			line = get_next_line(fd);
			if (!line)
				break;
			saved = ft_strjoin_free(saved, line);
			free(line);
		}
		map.map = ft_split(saved, '\n');
		free(saved);
	}
	close(fd);
	return (map.map);
}

