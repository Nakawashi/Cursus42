/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:51:45 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/17 16:33:38 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (map_check(argv[1], &game))
		{
			game_init(&game);
			game_hooks(&game);
			mlx_loop(game.mlx_id);
			free_map(game.map);
		}
		else
		{
			free_map(game.map);
			exit(1);
		}
	}
	else
	{
		ft_printf("Invalid arguments : \n");
		ft_printf("[program name] [assets\\maps\\[filename.ber]]\n");
		exit(1);
	}
	return (0);
}
