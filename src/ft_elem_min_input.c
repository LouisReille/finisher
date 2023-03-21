/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem_min_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:25:43 by lreille           #+#    #+#             */
/*   Updated: 2023/03/20 22:00:47 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

void	ft_sp_input(t_item *data, char *str)
{
	char	**sphere;
	t_info	object;

	sphere = ft_space_split(str);
	object.pos = ft_split(sphere[1], ',');
	object.color = ft_split(sphere[3], ',');
	object.radius = ft_atod(sphere[2]);
	if (data->tool.tran_rot > 0)
		object.translation = ft_split(sphere[4], ',');
	data->objet = add_sphere(data, object);
}

void	ft_pl_input(t_item *data, char *str)
{
	char	**plane;
	t_info	object;

	plane = ft_space_split(str);
	object.pos = ft_split(plane[1], ',');
	object.vector = ft_split(plane[2], ',');
	object.color = ft_split(plane[3], ',');
	if (data->tool.tran_rot > 0)
	{
		object.translation = ft_split(plane[4], ',');
		if (data->tool.tran_rot == 2)
			object.rotation = ft_split(plane[5], ',');
	}
	data->objet = add_plane(data, object);
}

void	ft_cy_input(t_item *data, char *str)
{
	char	**cylinder;
	t_info	object;

	cylinder = ft_space_split(str);
	object.pos = ft_split(cylinder[1], ',');
	object.vector = ft_split(cylinder[2], ',');
	object.radius = ft_atod(cylinder[3]);
	object.height = ft_atod(cylinder[4]);
	object.color = ft_split(cylinder[5], ',');
	if (data->tool.tran_rot > 0)
	{
		object.translation = ft_split(cylinder[6], ',');
		if (data->tool.tran_rot == 2)
			object.rotation = ft_split(cylinder[7], ',');
	}
	data->objet = add_cylinder(data, object);
}
