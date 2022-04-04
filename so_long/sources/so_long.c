/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:51:45 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/05 00:58:16 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Invalid number of arguments.\n--> [program name] [.ber file]");
		exit(1);
	}
	if (map_check(argv[1], ".ber")) // check si le format de l'image est bien un .ber. 1 si oui, 0 si non.
	{
		t_window window;
		void	*mlx_id;

		mlx_id = mlx_init();
		window.id = mlx_new_window(mlx_id, 500, 500, "Half Life 3 Deluxe Edition");
		mlx_loop(mlx_id);
	}
	else
	{
		ft_printf("--> Map format invalid. \n--> [.ber] required");
		exit(1);
	}
	return (0);
}

// gcc -Wall -Wextra -Werror -Imlx -Lmlx mlx/libmlx.a -framework OpenGL -framework AppKit main.cÓ