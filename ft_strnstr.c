/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiaz-ca <mdiaz-ca@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:33:53 by mdiaz-ca          #+#    #+#             */
/*   Updated: 2023/03/16 19:54:15 by mdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (needle[0] == 0)
		return ((char *)haystack);
//	if (ft_strlen(haystack) > len || ft_strlen(needle) <= len || ft_strlen(haystack) < ft_strlen(needle))
//		return (NULL);
	i = 0;
	while (haystack[i] != '\0' && i < ft_strlen(needle))
	{
		if (ft_strlen(needle) > len)
		{
			if (!ft_strncmp((char *)&haystack[i], needle, ft_strlen(needle)))
				return ((char *)haystack + i);
		}
		else
		{
			if (!ft_strncmp((char *)&haystack[i], needle, len + 1))
                                return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
/*
int main()
{
	printf("%s", ft_strnstr("abcdefgh", "abc", 2));
	return 0;
}*/
