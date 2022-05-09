/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:51:45 by lgenevey          #+#    #+#             */
/*   Updated: 2022/05/09 18:35:31 by lgenevey         ###   ########.fr       */
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
			game_hooks(&game);
			//afficher les images selon le contenu de la map
			//mlx_key_hook(game.win_id, deal_key, (void *)0);
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
