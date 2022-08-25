/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:49:13 by lgenevey          #+#    #+#             */
/*   Updated: 2022/03/19 19:03:05 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* &table[n % base]
*  on veut l'index que nous donne le reste du modulo qui correspond
*  a la valeur en hexadecimal
*/

#include "ft_printf.h"

int	ft_putbase(unsigned int n, unsigned int base, char *table)
{
	int	count;

	count = 0;
	if (n >= 0 && n < base)
		return (write(1, &table[n % base], 1));
	else
	{
		count += ft_putbase_lg(n / base, base, table);
		return (write(1, &table[n % base], 1) + count);
	}
	return (count);
}
