#include "minilibx/mlx.h"
#include <unistd.h>

int main()
{
	write(1, "coucou", 6);
	return (0);
}

// gcc -Wall -Wextra -Werror -Iminilibx -Lminilibx -framework OpenGL -framework AppKit main.c
