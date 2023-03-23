/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiaz-ca <mdiaz-ca@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:33:53 by mdiaz-ca          #+#    #+#             */
/*   Updated: 2023/03/15 18:54:59 by mdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_alloc(char const *s, char c, char **arr)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				i++;
				k++;
			}
			arr[j] = (char *)malloc(sizeof(char) * (k + 1));
			k = 0;
			j++;
		}
		i++;
	}
}

void	ft_cpy(char const *s, char c, char **arr)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				arr[j][k] = s[i];
				i++;
				k++;
			}
			arr[j][k] = '\0';
			k = 0;
			j++;
		}
		i++;
	}
	arr[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
		i++;
	}
	arr = (char **)malloc(sizeof(char *) * (j + 1));
	if (!arr)
		return (NULL);
	ft_alloc(s, c, arr);
	ft_cpy(s, c, arr);
	return (arr);
}

#include <mcheck.h>
int	main(void)
{
	char	**tab = ft_split("chinimala", ' ');
	mcheck(tab, 2 * (sizeof(char *)));
		printf("egual");
	
	printf("%lu\n", (sizeof(char *) * 2));
	printf("%lu\n", (sizeof(*tab)));
	printf("%s\n", tab);

	return (0);
}