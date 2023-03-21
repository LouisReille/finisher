/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:10:16 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/21 20:55:59 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

void	ft_check_input(t_item *data, char *line)
{
	int		i;
	char	**parc;

	i = 0;
	parc = ft_space_split(line);
	data->parsing.check = -1;
	data->parsing.indice = 0;
	data->tool.tran_rot = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_isalpha(line[i]))
	{
		check_data(data, parc);
		if (data->parsing.check == 0)
			ft_error(data, E1009);
		else
			data->parsing.indice = check_element(data,
					parc, data->parsing.check);
	}
	else if (!ft_isalpha(line[i]) && line[i])
		ft_error(data, E1010);
}

char	*ft_check_file(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s2[j])
		return ((char *)s1);
	while (s1[i])
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			j = 1;
			while (s2[j] && s2[j] == s1[i + j])
				j++;
			if (!s2[j] && !s1[i + j])
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}

void	read_line(t_item *data, int fd)
{
	int		r;
	char	*line;

	ft_init_resolution(data);
	r = get_next_line(fd, &line);
	while (r > 0)
	{
		data->parsing.error++;
		ft_check_input(data, line);
		ft_input(data, data->parsing.indice, line);
		r = get_next_line(fd, &line);
	}
	if (r == 0)
	{
		data->parsing.error++;
		ft_check_input(data, line);
		ft_input(data, data->parsing.indice, line);
	}
	if (r == -1)
		exit(1);
}

static void	check(t_item *data, char **argv, int fd)
{
	if (fd == -1)
		ft_error(data, E1004);
	if (ft_check_file(argv[1], ".rt"))
		read_line(data, fd);
	else
		ft_error(data, E1003);
}

void	parsing(t_item *data, char **argv, int argc)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (argc == 2)
	{
		check(data, argv, fd);
		if (data->parsing.c == 0)
			ft_error(data, E1005);
	}
	else
	{
		if (argc == 1)
			ft_error(data, E1001);
		else
			ft_error(data, E1002);
	}
}
