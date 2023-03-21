/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:51:44 by cdescour          #+#    #+#             */
/*   Updated: 2022/03/28 21:14:53 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**free_splited(char **splited, int k)
{
	while (k)
		free(splited[k - 1]);
	free(splited);
	return (NULL);
}

static	char	**ft_countsep(char const *s, char c, int *i)
{
	char	**splited;

	if (!s)
		return (NULL);
	*i = 0;
	while (*s)
	{
		if (*s == c && (*(s + 1) != c && *(s + 1) != '\0'))
			*i = *i + 1;
		s++;
	}
	splited = (char **)malloc(sizeof(char *) * (*i + 2));
	if (!splited)
		return (NULL);
	return (splited);
}

static	char
	*ft_strldup(char ***splited, const char *s1, unsigned int j, int *k)
{
	char	*str;

	str = (char *)malloc(j + 1);
	if (!str)
		*splited = free_splited(*splited, *k);
	ft_strlcpy(str, s1, j + 1);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char			**splited;
	int				i;
	unsigned int	j;
	int				k;

	k = 0;
	splited = ft_countsep(s, c, &i);
	if (!s || !splited)
		return (NULL);
	while (*s && splited)
	{
		j = 0;
		while (*s == c)
			s++;
		while (s[j] != c && s[j] != '\0')
			j++;
		if (j)
			splited[k++] = ft_strldup(&splited, s, j, &k);
		s += j;
		while (*s == c && *s)
			s++;
	}
	splited[k] = 0;
	return (splited);
}
