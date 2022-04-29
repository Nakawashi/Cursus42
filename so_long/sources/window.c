/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:00:06 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/29 14:50:00 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Here, every key that we have to hook :
	- ESC to quit the programm
	- WASD to move the player and display it in the window

*/


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
