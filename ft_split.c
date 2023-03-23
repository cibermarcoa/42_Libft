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

char    **ft_split(char const *s, char c)
{
    char    **arr;

	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
		i++;
	}
	// if (j == 0 && ft_isascii(s[i - 1]))
	// 		j++;
	arr = (char **)malloc(sizeof(char *) * (j + 1));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
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
						//printf("%c", arr[j][k]);
						i++;
						k++;
					}
				arr[j][k] = '\0';
				//printf("\n");
				k = 0;
				j++;
			}
			i++;
	}




	    arr[j] = NULL;

	// for (int i = 0; i < j; i++)
    //     printf("%s\n", arr[i]);
	return (arr);
}

// int	main(void)
// {
// 	char **split;
// 	split = ft_split("", 'z');
// 	int	i = 0;
// 	int	j = 0;
// 	printf("%s", split[0]);
// 	while (split[i])
// 	{
// 		printf("%s\n", split[i]);
// 		i++;
// 	}
// 	return (0);
// }
