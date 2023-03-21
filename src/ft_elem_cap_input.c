/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem_cap_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 11:34:47 by lreille           #+#    #+#             */
/*   Updated: 2023/03/21 22:10:08 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

void	ft_a_input(t_item *data, char *str)
{
	char	**amb;
	char	**rgb;

	amb = ft_space_split(str);
	rgb = ft_split(amb[2], ',');
	data->ambient.int_amb = ft_atod(amb[1]);
	data->ambient.rgb_amb = r_g_b(rgb[0], rgb[1], rgb[2]);
	data->ambient.rgb_amb = make_range(data->ambient.rgb_amb);
	data->parsing.a = 1;
}

void	ft_c_input(t_item *data, char *str)
{
	char	**camera;
	t_info	object;

	camera = ft_space_split(str);
	object.pos = ft_split(camera[1], ',');
	object.vector = ft_split(camera[2], ',');
	object.fov = ft_atod(camera[3]);
	if (data->tool.tran_rot > 0)
	{
		object.translation = ft_split(camera[4], ',');
		if (data->tool.tran_rot == 2)
			object.rotation = ft_split(camera[5], ',');
	}
	data->camera = add_camera(data, object);
	data->parsing.c = 1;
}

void	ft_l_input(t_item *data, char *str)
{
	char	**light;
	t_info	object;

	light = ft_space_split(str);
	object.pos = ft_split(light[1], ',');
	object.color = ft_split(light[3], ',');
	object.int_light = ft_atod(light[2]);
	if (data->tool.tran_rot > 0)
		object.translation = ft_split(light[4], ',');
	data->light = add_light(data, object);
}
