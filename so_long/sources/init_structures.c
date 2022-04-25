/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:27:56 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/25 14:30:03 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Parce qu'il faut bien initialiser les variables avant utilisation
*/

void	window_init(t_window *window)
{
	window->win_height = 0;
	window->win_width = 0;
}

void	map_init(t_map *map)
{
	map->map = NULL;
	map->line_lenght = 0;
	map->rows_nb = 0;
	map->count_P = 0;
	map->count_E = 0;
	map->count_C = 0;
}

// void	img_init(t_img *img)
// {

// }
