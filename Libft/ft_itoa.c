/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:41:36 by cdescour          #+#    #+#             */
/*   Updated: 2022/03/21 13:53:21 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_itoa(int n)
{
	int	len;

	len = 2;
	if (n == 0)
		return (len);
	if (n >= 0)
	{
		n = -n;
		len = 1;
	}
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len_itoa;

	len_itoa = ft_len_itoa(n);
	str = NULL;
	str = malloc(sizeof(char) * len_itoa);
	if (!str)
		return (NULL);
	len_itoa--;
	str[len_itoa] = 0;
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	else
		n = -n;
	while (n != 0)
	{
		len_itoa--;
		str[len_itoa] = -(n % 10 - '0');
		n = n / 10;
	}
	return (str);
}
