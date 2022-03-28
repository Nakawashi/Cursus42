#include "mlx/mlx.h"
#include <unistd.h>

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "Half Life 3");
	img_ptr = mlx_new_image(mlx_ptr, 48, 48);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}

// gcc -Wall -Wextra -Werror -Imlx -Lmlx mlx/libmlx.a -framework OpenGL -framework AppKit main.c