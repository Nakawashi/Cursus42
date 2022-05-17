/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:22:05 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/17 15:02:18 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	xlsx or docx would not work here, but it's easy to update
	Remember : ft_strncmp returns 0 if both are the same

	const char *file_path :	(../assets/map/filename.ber)
	char *extension :		dot + file extension = ".ber" + "\0" = 5
*/
int	check_ext(const char *file_path, char *extension)
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
	if each line has same nb of char, it's a rectangle
	compare all lines with the first (map->line_lenght)
	map_height and map_width are initialized here with real values.
*/
int	is_rectangle(t_game *game)
{
	int	current_line;
	int	i;

	if (!game->map)
		return (0);
	game->map_width = ft_strlen(game->map[0]);
	i = 1;
	while (game->map[i])
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
	first and last line should be 1
	first and last char per line should be 1
	had to intervert j and i to check horizontally :D
*/
int	check_walls_around(t_game *game)
{
	int	i;
	int	j;

	if (!game->map)
		return (0);
	while (game->map[game->map_height])
		game->map_height++;
	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if ((j == 0 || j == game->map_height - 1 || i == 0
					|| i == game->map_width - 1) && (game->map[j][i] != WALL))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

/*
	combined with check_assets below (split function for less than 25 lines)
*/
int	compare_assets(t_game *game, int i, int j)
{
	if (!game->map)
		return (0);
	if (game->map[i][j] == 'P' || game->map[i][j] == 'E'
		|| game->map[i][j] == 'C' || game->map[i][j] == '1'
		|| game->map[i][j] == '0')
	{
		if (game->map[i][j] == 'P')
			game->count_p++;
		else if (game->map[i][j] == 'E')
			game->count_e++;
		else if (game->map[i][j] == 'C')
			game->count_c++;
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
int	check_assets(t_game *game)
{
	int		i;
	int		j;

	if (!game->map)
		return (0);
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!compare_assets(game, i, j))
				return (0);
			j++;
		}
		i++;
	}
	if (game->count_p == 1 && game->count_e == 1 && game->count_c > 0)
		return (1);
	return (0);
}
