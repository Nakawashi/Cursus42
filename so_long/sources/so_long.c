/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:51:45 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/22 11:02:55 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map		map;

	if (argc == 2)
	{
		map_init(&map);
		map.map = read_map(argv[1]);
		if (map_check(argv[1], ".ber", &map))
		{
			void	*mlx_id;
			void	*win_id;

			mlx_id = mlx_init();
			win_id = mlx_new_window(mlx_id, 500, 500, "Half Life 3");
			mlx_loop(mlx_id);
		}
		free_map(map.map);
		exit(1);
	}
	else
	{
		ft_printf("Invalid nb of arguments.\n--> [program name] [.ber file]");
		exit(1);
	}
	return (0);
}
