/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:51:45 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/08 20:40:06 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Invalid nb of arguments.\n--> [program name] [.ber file]");
		exit(1);
	}
	if (map_check(argv[1], ".ber"))
	{
		t_window	window;
		void		*mlx_id;

		mlx_id = mlx_init();
		window.id = mlx_new_window(mlx_id, 500, 500, "Half Life 3");
		mlx_loop(mlx_id);
	}
	else
	{
		ft_printf("--> Map format invalid. \n--> [.ber] required");
		exit(1);
	}
	return (0);
}
