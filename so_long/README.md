# Description

> Créer un jeu en 2D dans lequel un dauphin s'échappe de la planete Terre après avoir mangé du poisson. <br>
> (Collecter des items avant de sortir du niveau). En utilisant la MiniLibX.

# MiniLibX

miniLibX manuals:
https://gontjarow.github.io/MiniLibX/

- man /usr/share/man/man3/mlx.1
- man /usr/share/man/man3/mlx_new_window.1	: window handler
- man /usr/share/man/man3/mlx_pixel_put.1	: draw inside window
- man /usr/share/man/man3/mlx_new_image.1	: manipulate images
- man /usr/share/man/man3/mlx_loop.1		: handle keyboard or mouse events

Flags de compilation sur MacOS : `-lmlx -framework OpenGL -framework AppKit`

## Petit exemple :

```C
#include <mlx.h>

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	// Fonction qui nous connecte au serveur graphique du Mac.
	// Renvoie un pointeur sur void qui correspond a l'identifiant de la connexion au serveur graphique.
	mlx_ptr = mlx_init();
	// Ouvrir une fenêtre. Renvoie l'id de la fenêtre que l'on crée.
	//Il est possible d'en ouvrir plusieurs en même temps, d'où le besoin de les différencier.
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "nom_de_la_fenetre");
	// Demande à MacOS de dessiner ce qu'on lui a demandé (ici ouvrir la fenêtre),
	// ecoute et recupère les evenements utilisateurs
	mlx_loop(mlx_ptr);
}
```


# Comment jouer

> Because the miniLibX uses Appkit and MX11 you need to link them adding `-lmlx -framework OpenGL -framework AppKit` when you compile.

# Lancer le jeu
