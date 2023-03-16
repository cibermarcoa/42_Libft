/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiaz-ca <mdiaz-ca@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:31:27 by mdiaz-ca          #+#    #+#             */
/*   Updated: 2023/03/16 19:05:19 by mdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_itoa_len(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_engeniring(char *str)
{;
	return (str);
}

char	*ft_itoa(int n)
{	
	size_t		len;
	char		*str;

	len = ft_itoa_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = 48;
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
			return (ft_engeniring(str));
		n *= -1;
	}
	while (n != 0 && len >= 0)
	{
		str[len-- - 1] = n % 10 + 48;
		n /= 10;
	}
	return (str);
}
