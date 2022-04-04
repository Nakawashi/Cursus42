/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:30:50 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/05 01:49:49 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

/*
    Combine all requirement for map parsing
    - Correct .ber extension
    - At least 4 lines, 4 columns to be coherent (square)
    - Walls around the map
    - Each asked items (E, P, C, 0, 1)
*/
int	map_check(const char *s, char *extension)
{
    if (check_img_extension(s, extension))
    {
        return (1);
    }
    return (0);
}

/*   
    Used in main file
    I took the decision to hardcode nb of extension's letters
    xlsx or docx would not work here, but it's easy to update
*/
int	check_img_extension(const char *s, char *extension)
{
	int		i;
    char    *ext;

	i = 3;
    ext = extension;
	while (i >= 0)
	{
		if (ft_strrchr(s, ext[i]) == NULL)
			return (0);
        ft_printf("inside extension[i] : [%c]\n", ext[i]);
		i--;
	}
    if (*ext == '.')
        return (1);
    return (0);
}

/*
    We want walls all around the map
*/
int check_walls_around(char *s)
{
    int i;
    int j;

    i = 0;
    while (s[i])
    {
        j = 0;
        while (s[j])
        {
            
            j++;
        }
        i++;
    }
    return (1);
}