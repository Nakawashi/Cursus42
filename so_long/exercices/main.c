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
	int	key_nb;

	key_nb = ft_putnbr(key);
	if (key_nb == 37)
		ft_putchar('L');
	if (key_nb == 38)
		ft_putchar('U');
	if (key_nb == 39)
		ft_putchar('R');
	if (key_nb == 40)
		ft_putchar('D');
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Fallout 4");
	//mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(mlx_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);	
}
