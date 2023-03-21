/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:27:19 by cdescour          #+#    #+#             */
/*   Updated: 2022/03/22 23:43:30 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lena;
	size_t	lenb;
	size_t	i;
	char	*str;

	i = 0;
	lena = ft_strlen(s1);
	lenb = ft_strlen(s2);
	str = malloc(sizeof(char) * (lena + lenb + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[i - lena])
	{
		str[i] = s2[i - lena];
		i++;
	}
	str[i] = 0;
	return (str);
}
