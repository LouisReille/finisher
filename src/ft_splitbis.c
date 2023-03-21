/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitbis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:37:29 by lreille           #+#    #+#             */
/*   Updated: 2023/03/21 21:52:16 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

static int	count_words(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
		if (str[i] && str[i] != ' ' && str[i] != '\t')
		{
			i++;
			j++;
		}
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
	}
	return (j);
}

static void	*leak_check(char **tab, int j)
{
	j = j - 1;
	while (tab[j])
	{
		free(tab[j]);
		j--;
	}
	free(tab);
	return (NULL);
}

static int	tab_count(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
	{
		i++;
	}
	return (i);
}

static char	*alloc(char **tab, char *src)
{
	int			i;
	int			j;
	int			o;

	j = 0;
	o = 0;
	while (src[o] == ' ' || src[o] == '\t')
		o++;
	while (j < count_words(src))
	{
		i = 0;
		tab[j] = malloc(sizeof(char) * (tab_count(&src[o]) + 1));
		if (!tab[j])
			return (leak_check(tab, j));
		while ((src[o] != '\t' && src[o] != ' ') && src[o])
			tab[j][i++] = src[o++];
		tab[j][i] = '\0';
		while ((src[o] == '\t' || src[o] == ' ') && src[o])
			o++;
		j++;
	}
	tab[j] = NULL;
	return (*tab);
}

char	**ft_space_split(char const *s)
{
	int			i;
	int			j;
	int			o;
	char		**tab;
	char		*str;

	o = 0;
	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = (char *)s;
	tab = malloc(sizeof(char *) * (count_words(str) + 1));
	if (!tab)
		return (NULL);
	tab[j] = alloc(tab, str);
	return (tab);
}
