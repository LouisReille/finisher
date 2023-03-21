/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem_cap_inputbis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:49:29 by lreille           #+#    #+#             */
/*   Updated: 2023/03/21 23:07:43 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

t_light	*add_light(t_item *data, t_info object)
{
	t_light	*tmp;
	t_light	*new_light;

	tmp = data->light;
	new_light = (t_light *)malloc(sizeof(t_light));
	if (!new_light)
		free_exit(data);
	new_light->previous = NULL;
	new_light->next = NULL;
	new_light->pos = x_y_z(object.pos[0], object.pos[1], object.pos[2]);
	new_light->int_light = object.int_light;
	new_light->rgb_light = make_rrange(255);
	if (data->tool.tran_rot > 0)
	{
		new_light->translation = x_y_z(object.translation[0],
				object.translation[1], object.translation[2]);
		new_light->pos = vector_add(new_light->pos, new_light->translation);
	}
	if (data->light == NULL)
		return (new_light);
	while (tmp->next != NULL)
		tmp = tmp->next;
	new_light->previous = tmp;
	tmp->next = new_light;
	return (data->light);
}

static void	trans_rot_c(t_item *data, t_camera *new_camera, t_info object)
{
	if (data->tool.tran_rot > 0)
	{
		new_camera->translation = x_y_z(object.translation[0],
				object.translation[1], object.translation[2]);
		new_camera->pos = vector_add(new_camera->pos, new_camera->translation);
		if (data->tool.tran_rot == 2)
		{
			new_camera->rotation = x_y_z(object.rotation[0],
					object.rotation[1], object.rotation[2]);
			new_camera->ort_vec = rot_vector(new_camera->ort_vec,
					new_camera->rotation);
		}
	}
}

t_camera	*add_camera(t_item *data, t_info object)
{
	t_camera	*tmp;
	t_camera	*new_camera;

	tmp = data->camera;
	new_camera = (t_camera *)malloc(sizeof(t_camera));
	if (!new_camera)
		free_exit(data);
	new_camera->previous = NULL;
	new_camera->next = NULL;
	new_camera->pos = x_y_z(object.pos[0], object.pos[1], object.pos[2]);
	new_camera->ort_vec = x_y_z(object.vector[0],
			object.vector[1], object.vector[2]);
	new_camera->fov = object.fov;
	trans_rot_c(data, new_camera, object);
	if (data->camera == NULL)
		return (new_camera);
	while (tmp->next != NULL)
		tmp = tmp->next;
	new_camera->previous = tmp;
	tmp->next = new_camera;
	return (data->camera);
}
