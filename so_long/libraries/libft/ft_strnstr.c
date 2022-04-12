/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:13:58 by lgenevey          #+#    #+#             */
/*   Updated: 2022/04/12 20:02:55 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	litsize;

	litsize = ft_strlen(needle);
	if (!litsize)
		return ((char *)haystack);
	while (*haystack && litsize <= len--)
	{
		if (!ft_strncmp(haystack, needle, litsize))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}