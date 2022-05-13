/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:51:45 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/13 17:51:55 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_game	game;

		if (map_check(argv[1], &game))
		{
			game_init(&game);
			printf("nb_movements 1 : %d\n", game.nb_movements);
			game.nb_movements = 0;
			game_hooks(&game);
			printf("nb_movements 2 : %d\n", game.nb_movements);
			mlx_loop(game.mlx_id);
		}
		else
		{
			free_map(game.map);
			exit(1);
		}
	}
	else
	{
		ft_printf("Invalid nb of arguments.\n--> [program name] [.ber file]");
		exit(1);
	}
	return (0);
}
