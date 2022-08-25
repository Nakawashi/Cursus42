#include "mlx/mlx.h"
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	deal_key(int key, void *param)
{
	(void) *param;

	ft_putnbr(key);
	if (key == 13)
		ft_putchar('w');
	if (key == 0)
		ft_putchar('a');
	if (key == 1)
		ft_putchar('s');
	if (key == 2)
		ft_putchar('D');
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "Half Life 3");
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
/*gcc sources/so_long.c sources/so_long.h -Ilibraries/minilibx  libraries/minilibx/libmlx.a libraries/libft/ft_printf/libftprintf.a  -framework OpenGL -framework AppKit*/