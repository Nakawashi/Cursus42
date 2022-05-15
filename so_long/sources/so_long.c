/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:51:45 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/15 11:37:08 by nakawashi        ###   ########.fr       */
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
