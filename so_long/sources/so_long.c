/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:51:45 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/01 18:29:54 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_img_extension(char *s, char *extension)
{
	int		i;

	i = 3;
	while (i >= 0)
	{
		if (ft_strrchr(s, extension[i]) == NULL)
			return (0);
		i--;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("--> Arguments invalid.\n--> [.ber] file needed.");
		exit(1);
	}
	if (check_img_extension(argv[1], ".ber")) // check si le format de l'image est bien un .ber. 1 si oui, 0 si non.
	{
		t_window window;
		void	*mlx_id;

		mlx_id = mlx_init();
		window.id = mlx_new_window(mlx_id, 500, 500, "Half Life 3 Deluxe Edition");
		mlx_loop(mlx_id);
	}
	else
	{
		ft_printf("--> Map format invalid. \n--> [.ber] wanted");
		exit(1);
	}




	// void	*mlx_ptr;
	// void	*win_ptr;
	// void	*img_ptr;

	// mlx_ptr = mlx_init();
	// win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "Half Life 3");
	// img_ptr = mlx_new_image(mlx_ptr, 48, 48);
	// mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	// mlx_loop(mlx_ptr);
	return (0);
}

// gcc -Wall -Wextra -Werror -Imlx -Lmlx mlx/libmlx.a -framework OpenGL -framework AppKit main.cÓ