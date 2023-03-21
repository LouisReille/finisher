/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:21:30 by lreille           #+#    #+#             */
/*   Updated: 2023/03/21 22:15:49 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

void	just_calcul(t_item *data)
{
	while (data->objet->i != data->tool.index)
		data->objet = data->objet->next;
	if (data->objet->data == SPH)
		sphere_p_n(data);
	else if (data->objet->data == PLA)
		plane_p_n(data);
	else if (data->objet->data == CYL)
		cylinder_p_n(data);
}

double	object_sp_cy(t_item *data, t_objet *tmp, t_ray *shade)
{
	double	save;
	t_objet	*temporaire;

	temporaire = tmp;
	if (data->tool.data == SPH || data->tool.data == CYL)
	{
		while (temporaire->i != data->tool.index)
			temporaire = temporaire->next;
		if (data->tool.data == SPH)
			save = hit_sphere(temporaire, shade);
		if (data->tool.data == CYL)
			save = hit_cylinder(temporaire, shade);
		temporaire = tmp;
		return (save);
	}
	return (0);
}

static void	check_shadow(t_item *data, double save, int *index)
{
	if (save == 0)
	{
		if (*index == 0)
		{
			*index = 1;
			data->shad.intersect = 1;
			data->shad.degre += 0.5;
		}
	}
}

void	hit_objet2(t_item *data, t_ray *shade, t_objet *tmp)
{
	int		index;
	double	save;
	double	has_inter;
	t_objet	*temporaire;

	temporaire = tmp;
	index = 0;
	has_inter = 0;
	save = object_sp_cy(data, tmp, shade);
	while (temporaire != NULL)
	{
		if (temporaire->i == data->tool.index)
			temporaire = temporaire->next;
		if (temporaire != NULL)
		{
			witch_object(temporaire, shade, &has_inter);
			if (has_inter > 0 && has_inter <= shade->lenght)
				check_shadow(data, save, &index);
			temporaire = temporaire->next;
		}
	}
}

void	hit_objet(t_item *data, double *t1)
{
	t_ray	*ray;
	t_objet	*tmp;
	double	has_inter;

	ray = &data->ray;
	data->tool.data = 0;
	tmp = data->objet;
	data->tool.intersect = 0;
	has_inter = 0;
	while (data->objet != NULL)
	{
		witch_object(data->objet, ray, &has_inter);
		if (has_inter > 0 && has_inter < *t1)
		{
			data->tool.data = data->objet->data;
			*t1 = has_inter;
			data->tool.index = data->objet->i;
			data->objet->t = has_inter;
			data->tool.intersect = 1;
		}
		data->objet = data->objet->next;
	}
	data->objet = tmp;
	if (data->tool.intersect == 1)
		just_calcul(data);
}
