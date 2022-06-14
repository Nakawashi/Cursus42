/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:43:58 by lgenevey          #+#    #+#             */
/*   Updated: 2022/06/14 18:20:04 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	**str;

	if (argc > 1)
	{
		str = get_user_data(argc, argv);
		is_number(str);
		find_duplicate(str);
		if(!fill_stack(str, &a))
		{
			ft_lstclear(&(a.top), free);
			ft_free_array(str);
			return (0);
		}
		init_stack(&b);
		push_swap(&a, &b);
	}
	return (0);
}
